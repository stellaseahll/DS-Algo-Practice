#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int main(){
	int n;
	int t,c;
	int x;
	int curr;
	string str;
	vector<string> name;
	for (int i=0; i<4; i++){
		for (int j=0; j<13; j++){
			ostringstream oss;
			if (j<9)
				oss<<j+2<<" of ";
			else if (j==12)
				oss<<"Ace of ";
			else if (j==9)
				oss<<"Jack of ";
			else if (j==10)
				oss<<"Queen of ";
			else if (j==11)
				oss<<"King of ";
			if (i==0)
				oss<<"Clubs";
			else if (i==1)
				oss<<"Diamonds";
			else if (i==2)
				oss<<"Hearts";
			else if (i==3)
				oss<<"Spades";
			name.push_back(oss.str());
		}
	}
	scanf("%d\n",&n);
	for (int i=0; i<n; i++){
		scanf("%d",&t);
		int shuffle[t][52];
		int card[2][52];
		for (int j=0; j<52; j++){
			card[0][j]=j;
		}
		curr=0;
		for (int j=0; j<t; j++){
			for (int k=0; k<52; k++){
				scanf("%d",&c);
				shuffle[j][k]=c-1;
			}
		}
		getline(cin,str);
		getline(cin,str);
		while (!str.empty()){
			istringstream iss;
			iss.str(str);
			iss>>x;
			for (int k=0; k<52; k++){
				card[!curr][k]=card[curr][shuffle[x-1][k]];
			}
			curr=!curr;
			getline(cin,str);
		}
		for (int k=0; k<52; k++){
			cout<<name[card[curr][k]]<<endl;
		}
		cout<<endl;
		
	}
	return 0;
}