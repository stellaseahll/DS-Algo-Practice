#include <iostream>
#include <cstdio>
using namespace std;


int main(){
	int n;
	int row, col;
	scanf("%d",&n);
	int out[n];
	for (int i=0; i<n; i++){
		scanf("%d%d",&row,&col);
		out[i]=(row/3)*(col/3);
	}
	for (int i=0; i<n; i++){
		printf("%d\n",out[i]);
	}
	return 0;
}