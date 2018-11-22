#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <stack>
using namespace std;

int main(){
	string str;
	cin>>str;
	while (str!="#"){
		stack<int> p[2], deck;
		int tmp;
		int top;
		int is1;
		int loser;
		for (int i=0; i<52; i++){
			tmp=0;
			if (str[1]=='A')
				tmp=4;
			else if (str[1]=='K')
				tmp=3;
			else if (str[1]=='Q')
				tmp=2;
			else if (str[1]=='J')
				tmp=1;
			else if (str[1]=='T')
				tmp=-10;
			else if (str[1]=='9')
				tmp=-9;
			else if (str[1]=='8')
				tmp=-8;
			else if (str[1]=='7')
				tmp=-7;
			else if (str[1]=='6')
				tmp=-6;
			else if (str[1]=='5')
				tmp=-5;
			else if (str[1]=='4')
				tmp=-4;
			else if (str[1]=='3')
				tmp=-3;
			else if (str[1]=='2')
				tmp=-2;
			if (i%2)
				p[0].push(tmp);
			else
				p[1].push(tmp);
			cin>>str;
		}
		loser=-1;
		is1=0;
		tmp=p[1].top();
		deck.push(tmp);
		p[1].pop();
		while (loser==-1){
			top=deck.top();
			if (top<0){
				if (p[is1].empty()){
					loser=is1;
					break;
				}
				tmp=p[is1].top();
				deck.push(tmp);
				p[is1].pop();
				is1=!is1;
			}
			else{
				tmp=-10;
				while (top--&&tmp<0){
					if (p[is1].empty()){
						loser=is1;
						break;
					}
					tmp=p[is1].top();
					deck.push(tmp);
					p[is1].pop();
				}
				if (top==-1&&deck.top()<0){
					stack<int> tmp1;
					while (!p[!is1].empty()){
						tmp1.push(p[!is1].top());
						p[!is1].pop();
					}
					while (!deck.empty()){
						p[!is1].push(deck.top());
						deck.pop();
					}
					while (!tmp1.empty()){
						p[!is1].push(tmp1.top());
						tmp1.pop();
					}
					tmp=p[!is1].top();
					deck.push(tmp);
					p[!is1].pop();	
				}
				else{
					is1=!is1;
				}
			}
		}
		cout<<!loser+1<<right<<setw(3)<<52-deck.size()<<endl;
	}
	
	return 0;
}