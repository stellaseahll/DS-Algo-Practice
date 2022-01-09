#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
	int n;
	int prev, curr;
	bool isAsc, isDes;
	scanf("%d",&n);
	int out[n];
	for (int i=0; i<n; i++){
		scanf("%d",&prev);
		isAsc=true;
		isDes=true;
		for (int j=1; j<10; j++){
			scanf("%d",&curr);
			if (curr>prev)
				isDes=false;
			if (curr<prev)
				isAsc=false;
			prev=curr;
		}
		out[i]=isDes||isAsc;
	}
	printf("Lumberjacks:\n");
	for (int i=0; i<n; i++){
		if (out[i])
			printf("Ordered\n");
		else
			printf("Unordered\n");
	}
	
	return 0;
}