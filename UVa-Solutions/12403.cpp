#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int main(){
	int n;
	int x;
	string s;
	vector<int> out;
	int amt=0;
	scanf("%d",&n);
	for (int i=0; i<n; i++){
		cin>>s;
		if (s=="report")
			out.push_back(amt);
		else{
			cin>>x;
			amt+=x;
		}
	}
	for (int i=0; i<out.size(); i++){
		printf("%d\n",out[i]);
	}	

	return 0;
}