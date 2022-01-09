#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <stack>
#include <utility>
using namespace std;

int main(){
	int c,r;
	scanf("%d%d",&c,&r);
	string strtmp;
	int tmp,tmp2;
	int idx;
	int D, sum;
	vector<string> name;
	vector< pair<int,int> > memory;
	vector< vector <int> > bound;
	pair<int,int> tmpPair;
	for (int i=0; i<c; i++){
		vector<int> tmpVec;
		cin>>strtmp;
		name.push_back(strtmp);
		cin>>tmpPair.first>>tmpPair.second;
		memory.push_back(tmpPair);
		scanf("%d",&tmp2);
		for (int j=0; j<tmp2; j++){
			cin>>tmp;
			tmpVec.push_back(tmp);
			cin>>tmp;
			tmpVec.push_back(tmp);
		}
		bound.push_back(tmpVec);
	}
	while (r--){
		getline(cin,strtmp);
		cin>>strtmp;
		for (int j=0; j<c; j++){
			if (strtmp==name[j]){
				idx=j;
				//break;
			}
		}
		D=bound[idx].size()/2;
		cout<<name[idx]<<"[";
		cin>>tmp;
		cout<<tmp;
		sum=(tmp-bound[idx][0]);
		for (int j=1; j<D; j++){
			cin>>tmp;
			cout<<", "<<tmp;
			sum=sum*(bound[idx][j*2+1]-bound[idx][j*2]+1)+tmp-bound[idx][j*2];
		}
		cout<<"] = "<<(sum)*memory[idx].second+memory[idx].first<<endl;
	}
	return 0;
}