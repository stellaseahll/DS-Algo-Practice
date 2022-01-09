#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n;
	int A[3];
	scanf("%d",&n);
	int out[n];
	for (int i=0; i<n; i++){
		scanf("%d%d%d",&A[0],&A[1],&A[2]);
		sort(A,A+3);
		out[i]=A[1];
	}
	for (int i=0; i<n; i++){
		cout<<"Case "<<i+1<<": ";
		printf("%d\n",out[i]);
	}
	return 0;
}