#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int sum;
	int row;
	int count=1;
	while (n!=0){
		int tmp[n];
		sum=0;
		for (int i=0; i<n; i++){
			scanf("%d",&tmp[i]);
			sum+=tmp[i];
		}
		row=sum/n;
		sum=0;
		for (int i=0; i<n; i++){
			if (tmp[i]>row)
				sum+=(tmp[i]-row);
		}
		cout<<"Set #"<<count++<<endl;
		cout<<"The minimum number of moves is "<<sum<<"."<<endl<<endl;
		scanf("%d",&n);
	}
}