#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

int main(){
	string strtmp;
	while (getline(cin,strtmp)){
		int store[4][5];
		int count[4];
		string str;
		memset(store,0,sizeof(store));
		memset(count,0,sizeof(count));
		istringstream iss;
		iss.str(strtmp);
		int suit,card;
		int point=0;
		for (int i=0; i<13; i++){
			iss>>str;
			card=0;
			if (str[0]=='A')
				card=4;
			else if (str[0]=='K')
				card=3;
			else if (str[0]=='Q')
				card=2;
			else if (str[0]=='J')
				card=1;
			if (str[1]=='S')
				suit=0;
			else if (str[1]=='H')
				suit=1;
			else if (str[1]=='D')
				suit=2;		
			else 
				suit=3;
			point+=card;
			count[suit]++;
			store[suit][card]=1;
		}

		int isStopped=1;
		for (int i=0; i<4; i++){
			if (store[i][4])
				continue;
			else if (store[i][3]&&count[i]>1)
				continue;
			else if (store[i][2]&&count[i]>2)
				continue;
			isStopped=0;
			break;
		}
		for (int i=0; i<4; i++){
			if (count[i]==1&&store[i][3]){
				point--;
			}
			if (count[i]<=2&&store[i][2]){
				point--;
			}
			if (count[i]<=3&&store[i][1]){
				point--;
			}			
		}
		if (point>=16&&isStopped){
			cout<<"BID NO-TRUMP"<<endl;
			continue;
		}

		int max=0;
		int best=10;
		for (int i=0; i<4; i++){
			if (count[i]<=1)
				point+=2;
			else if (count[i]==2)
				point++;
			if (count[i]>max){
				best=i;
				max=count[i];
			}
				
		}
		if (point<14){
			cout<<"PASS"<<endl;
			continue;
		}
		else{
			if (best==0)
				str="S";
			else if (best==1)
				str="H";
			else if (best==2)
				str="D";
			else if (best==3)
				str="C";
			cout<<"BID "<<str<<endl;
		}
	}
	
	return 0;
}