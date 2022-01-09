#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int n,k;
	int max,curr;
	scanf("%d",&n);
	int out[n];
	for (int i=0; i<n; i++){
		scanf("%d",&k);
		scanf("%d",&max);
		for (int j=1; j<k; j++){
			scanf("%d",&curr);
			if (max<curr)
				max=curr;
		}
		out[i]=max;
	}
	for (int i=0; i<n; i++){
		printf("Case %d: %d\n",i+1,out[i]);
	}
	
	return 0;
}