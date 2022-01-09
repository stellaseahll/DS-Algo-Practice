#include <iostream>
#include <cstdio>
#include <string>
using namespace std;


int main(){
	int n,f;
	int x,y;
	int diff;
	scanf("%d",&n);
	int out[n];
	for (int i=0; i<n; i++){
		scanf("%d",&f);
		out[i]=1;
		scanf("%d%d",&x,&y);
		diff=y-x;
		for (int j=1; j<f; j++){
			scanf("%d%d",&x,&y);
			if ((y-x)!=diff){
				out[i]=0;
			}
		}
	}
	for (int i=0; i<n-1; i++){
		if (out[i]){
			cout<<"yes"<<endl<<endl;
		}
		else
			cout<<"no"<<endl<<endl;
	}
	if (out[n-1]){
		cout<<"yes"<<endl;
	}
	else
		cout<<"no"<<endl;

	return 0;
}