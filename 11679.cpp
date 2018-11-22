#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main(){
	int B,D;
	int d,c,v;
	vector<int> out;
	scanf("%d%d",&B,&D);
	while (B+D){
		int money[B];
		for (int i=0; i<B; i++){
			scanf("%d",&money[i]);
		}
		for (int i=0; i<D; i++){
			scanf("%d%d%d",&d,&c,&v);
			money[d-1]-=v;
			money[c-1]+=v;
		}
		int check=1;
		for (int i=0; i<B; i++){
			if (money[i]<0)
				check=0;
		}
		out.push_back(check);
		scanf("%d%d",&B,&D);
	}
	for (int i=0; i<out.size(); i++){
		if (out[i])
			cout<<"S"<<endl;
		else
			cout<<"N"<<endl;
	}
	return 0;
}