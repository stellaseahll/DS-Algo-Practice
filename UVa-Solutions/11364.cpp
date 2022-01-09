#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n;
	int s;
	int min, max, tmp;
	scanf("%d",&n);
	int out[n];
	for (int i=0; i<n; i++){
		scanf("%d",&s);
		min=100; max=-1;
		for (int j=0; j<s; j++){
			scanf("%d",&tmp);
			if (tmp<min)
				min=tmp;
			if (tmp>max)
				max=tmp;
		}
		out[i]=2*(max-min);
	}
	for (int i=0; i<n; i++){
		printf("%d\n",out[i]);
	}		

	return 0;
}