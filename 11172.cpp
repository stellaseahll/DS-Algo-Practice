#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n;
	int a,b;
	scanf("%d",&n);
	char out[n];
	for (int i=0; i<n; i++){
		scanf("%d%d",&a,&b);
		if (a==b)
			out[i]='=';
		else if (a>b)
			out[i]='>';
		else
			out[i]='<';
	}
	for (int i=0; i<n; i++){
		printf("%c\n",out[i]);
	}		

	return 0;
}