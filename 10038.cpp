#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main(){
	string str;
	int n;
	int prev, curr;
	int tmp;
	int isJolly;
	while (getline(cin,str)){
		istringstream iss;
		iss.str(str);
		iss>>n;
		iss>>prev;
		vector<int> ideal, actual;
		ideal.push_back(1);
		for (int i=1; i<n; i++){
			iss>>curr;
			ideal.push_back(i+1);
			tmp=(curr-prev>0)? (curr-prev): (prev-curr);
			actual.push_back(tmp);
			prev=curr;
		}
		sort(actual.begin(), actual.end());
		isJolly=1;
		for (int i=0; i<n-1; i++){
			if (actual[i]!=ideal[i]){
				isJolly=0;
				break;
			}
		}
		if (isJolly)
			cout<<"Jolly"<<endl;
		else
			cout<<"Not jolly"<<endl;

	}
	return 0;
}