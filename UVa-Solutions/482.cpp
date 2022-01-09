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
	string strtmp, str; 
	int tmp;
	int n;
	scanf("%d",&n);
	getline(cin,strtmp);
	for (int k=0; k<n; k++){
		if (k!=0){
			printf("\n");
		}
		getline(cin,strtmp);
		getline(cin,strtmp);
		istringstream iss;
		iss.str(strtmp);
		vector<pair<int, string> > store;
		vector<int> idx;
		while (iss>>tmp){
			idx.push_back(tmp-1);
		}
		getline(cin,strtmp);
		int i=0;
		istringstream oss;
		oss.str(strtmp);
		while (oss>>str){
			pair<int, string> tmpPair;
			tmpPair.first=idx[i++];
			tmpPair.second=str;
			store.push_back(tmpPair);
		}
		sort(store.begin(), store.end());
		for (int j=0; j<idx.size(); j++){
			cout<<store[j].second<<endl;
		}
	}
	
}