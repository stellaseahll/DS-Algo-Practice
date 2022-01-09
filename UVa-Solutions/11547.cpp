#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n;
	int x;
	scanf("%d",&n);
	int out[n];
	for (int i=0; i<n; i++){
		scanf("%d",&x);
		x=(((x*567/9)+7492)*5)-498;
		if (x<0)
			x=-x;
		out[i]=(x/10)%10;
	}
	for (int i=0; i<n; i++){
		printf("%d\n",out[i]);
	}
	return 0;
}