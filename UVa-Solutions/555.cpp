#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	string str;
	getline(cin,str);
	string card="23456789TJQKA";
	string suit="CDSH";
	string player="SWNE";
	int id1,id2;
	int start;
	while (str!="#"){
		vector<int> p[4][4];
		start=player.find(str)+1;
		getline(cin,str);
		for (int i=0; i<str.size(); i+=2){
			id1=suit.find(str[i]);
			id2=card.find(str[i+1]);
			p[start%4][id1].push_back(id2);
			start++;
		}
		getline(cin,str);
		for (int i=0; i<str.size(); i+=2){
			id1=suit.find(str[i]);
			id2=card.find(str[i+1]);
			p[start%4][id1].push_back(id2);
			start++;
		}
		for (int i=0; i<4; i++){
			for (int j=0; j<4; j++){
				if (p[i][j].size())
					sort(p[i][j].begin(),p[i][j].end());
			}
		}
		for (int i=0; i<4; i++){
			printf("%c:",player[i]);
			for (int j=0; j<4; j++){
				for (int k=0; k<p[i][j].size(); k++){
						printf(" %c%c",suit[j],card[p[i][j][k]]);
				}
			}
			printf("\n");
		}
		getline(cin,str);
	}
	
	return 0;
}