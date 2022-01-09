#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int main(){
	int n,k;
	int pos, idx;
	string str;
	scanf("%d",&n);
	int out[n];
	for (int i=0; i<n; i++){
		scanf("%d",&k);
		int action[k];
		pos=0;
		for (int j=0; j<k; j++){
			cin>>str;
			if (str=="LEFT"){
				action[j]=-1;
			}
			else if (str=="RIGHT"){
				action[j]=1;
			}
			else{
				cin>>str;
				cin>>idx;
				action[j]=action[idx-1];
			}	
			pos+=action[j];
		}
		out[i]=pos;
	}
	for (int i=0; i<n; i++){
		printf("%d\n",out[i]);
	}
	
	return 0;
}