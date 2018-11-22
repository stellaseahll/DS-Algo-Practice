#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <cstring>
using namespace std;

int main(){
	int h,n;
	int d1,d2,cur,sum;
	for (int i=0; i<1000000; i++){
		for (int j=0; j<10000; j++){
			n=i+j;
		}
	}
	scanf("%d",&h);
	while (h!=0){
		scanf("%d",&n);
		sum=0;
		scanf("%d",&d1);
		cur=h-d1;
		for (int i=1; i<n; i++){
			scanf("%d",&d2);
			if (d2>d1){
				sum+=(d2-d1);
				cur-=d2-d1;
			}
			else if (d2<d1){
				cur+=d1-d2;
			}
			d1=d2;
		}
		cout<<sum+cur<<endl;
		scanf("%d",&h);
	}
	return 0;
}