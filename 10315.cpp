#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
string score(string str){
	string strCard="0023456789TJQKA", strSuit="CDHS";
	vector<int> type;
	vector<int> suit;
	int tmp;
	for (int i=0; i<4; i++){
		suit.push_back(0);
	}
	int card[15];
	int iC, iS;
	for (int i=0; i<15; i++){
		card[i]=0;
	}
	ostringstream oss;
	for (int i=0; i<str.length(); i+=2){
		iC=strCard.find(str[i]);
		iS=strSuit.find(str[i+1]);
		card[iC]++;
		if (card[iC]==1){
			type.push_back(iC);
		}
		suit[iS]++;
	}
	sort(suit.begin(), suit.end());
	sort(type.begin(), type.end());
	if (type.size()==2){
		if (card[type[0]]==1||card[type[0]]==4){ // 4 kind
			tmp= (card[type[0]]==4)?type[0]:type[1];
			if (tmp<10)
				oss<<0<<tmp<<8;
			else
				oss<<tmp<<8;
			return oss.str();
		}
		tmp= (card[type[0]]==3)?type[0]:type[1]; //full house
		if (tmp<10)
			oss<<0<<tmp<<7;
		else
			oss<<tmp<<7;
		return oss.str();
	}
	if (type.size()==3){ 
		if (card[type[0]]==2||card[type[1]]==2){ //2 pair
			tmp=-1;
			for (int i=2; i>=0; i--){
				if (card[type[i]]==2){
					if (type[i]<10)
						oss<<0<<type[i];
					else
						oss<<type[i];
				}
				else{
					tmp=type[i];
				}				
			}
			if (tmp<10)
				oss<<0<<tmp;
			else
				oss<<tmp;
			oss<<3;
			return oss.str();
		}
		for (int i=0; i<2; i++){ //3 kind
			if (card[type[i]]==3){
				if (type[i]<10)
					oss<<0<<type[i];
				else
					oss<<type[i];
				oss<<4;
				return oss.str();
			}
		}
	}
	if (type.size()==4){
		tmp=-1;
		for (int i=3; i>=0; i--){
			if (card[type[i]]==2){
				tmp=i;
				if (type[i]<10)
					oss<<0<<type[i];
				else
					oss<<type[i];
			}
		}
		for (int i=3; i>=0; i--){
			if (i==tmp)
				continue;
			if (type[i]<10)
				oss<<0<<type[i];
			else
				oss<<type[i];
		}
		oss<<2;
		return oss.str();
	}

	int isStraight=(type[4]-type[0]==4)?1:0;
	if (suit.back()==5){ 
		if (isStraight){ //straight flush
			if (type[4]<10)
				oss<<0<<type[4];
			else
				oss<<type[4];
			oss<<9;
			return oss.str();
		}
		for (int i=4; i>=0; i--){ //flush
			if (type[i]<10)
				oss<<0<<type[i];
			else
				oss<<type[i];
			
		}
		oss<<6;
		return oss.str();
	}
	if (isStraight){ //straight
		if (type[4]<10)
			oss<<0<<type[4];
		else
			oss<<type[4];
		oss<<5;
		return oss.str();
	}
	for (int i=4; i>=0; i--){
		if (type[i]<10)
			oss<<0<<type[i];
		else
			oss<<type[i];
	}
	oss<<1;
	return oss.str();
}

int main(){
	string score1, score2;
	string str,s;
	while (getline(cin,str)){
		istringstream iss;
		iss.str(str);
		str="";
		for (int i=0; i<5; i++){
			iss>>s;
			str+=s;
		}
		score1=score(str);
		str="";
		
		for (int i=0; i<5; i++){
			iss>>s;
			str+=s;
		}
		score2=score(str);
		
		if (score1[score1.size()-1]>score2[score2.size()-1]){
			cout<<"Black wins."<<endl;
		}
		else if (score1[score1.size()-1]<score2[score2.size()-1]){
			cout<<"White wins."<<endl;
		}
		else{
			if (score1>score2){
				cout<<"Black wins."<<endl;
			}
			else if (score2>score1){
				cout<<"White wins."<<endl;
			}
			else
				cout<<"Tie."<<endl;
		} 
	}
	return 0;
}