#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int n,k;
	int prev,curr;
	int high, low;
	scanf("%d",&n);
	int out[n][2];
	for (int i=0; i<n; i++){
		scanf("%d",&k);
		scanf("%d",&prev);
		high=0;
		low=0;
		for (int j=1; j<k; j++){
			scanf("%d",&curr);
			if (prev<curr)
				high++;
			if (curr<prev)
				low++;
			prev=curr;
		}
		out[i][0]=high;
		out[i][1]=low;
	}
	for (int i=0; i<n; i++){
		printf("Case %d: %d %d\n",i+1,out[i][0], out[i][1]);
	}
	
	return 0;
}