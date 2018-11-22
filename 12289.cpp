#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
	int n;
	int x;
	string s;
	scanf("%d",&n);
	int out[n];
	for (int i=0; i<n; i++){
		cin>>s;
		if (s.size()==5)
			out[i]=3;
		else {
			x=(s.substr(0,1)=="o")+(s.substr(1,1)=="n")+(s.substr(2,1)=="e");
			if (x>=2)
				out[i]=1;
			else
				out[i]=2;
		}
	}
	for (int i=0; i<n; i++){
		printf("%d\n",out[i]);
	}
	return 0;
}