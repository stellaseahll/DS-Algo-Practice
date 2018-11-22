#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
using namespace std;

int main(){
	int n, m, c;
	int tmp;
	vector<int> out;
	scanf("%d%d%d",&n,&m,&c);
	while (n!=0&&m!=0&&c!=0){
		int onoff[n];
		int amp[n];
		int cur=0;
		int maxcur=0;
		for (int i=0; i<n; i++){
			scanf("%d",&amp[i]);
			onoff[i]=0;
		}
		for (int j=0; j<m; j++){
			scanf("%d",&tmp);
			tmp=tmp-1;
			onoff[tmp]=!onoff[tmp];
			if (onoff[tmp])
				cur+=amp[tmp];
			else
				cur-=amp[tmp];
			if (cur>maxcur)
				maxcur=cur;
		}
		if (cur>c)
			out.push_back(0);
		else
			out.push_back(maxcur);
		scanf("%d%d%d",&n,&m,&c);
	}
	for (int i=0; i<out.size(); i++){
		cout<<"Sequence "<<i+1<<endl;
		if (out[i]){
			cout<<"Fuse was not blown."<<endl;
			cout<<"Maximal power consumption was "<<out[i]<<" amperes."<<endl;
		}
		else{
			cout<<"Fuse was blown."<<endl;
		}
		cout<<endl;	
	}
	return 0;
}