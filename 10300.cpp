#include <iostream>
#include <cstdio>
using namespace std;


int main(){
	int n,f;
	int a,b,c;
	scanf("%d",&n);
	int out[n];
	for (int i=0; i<n; i++){
		scanf("%d",&f);
		out[i]=0;
		for (int j=0; j<f; j++){
			scanf("%d%d%d",&a,&b,&c);
			out[i]+=a*c;
		}
	}
	for (int i=0; i<n-1; i++){
		printf("%d\n",out[i]);
	}
	printf("%d",out[n-1]);
	return 0;
}