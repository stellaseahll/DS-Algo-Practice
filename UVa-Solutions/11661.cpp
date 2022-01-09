#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <cstring>
using namespace std;

int main(){
	int n;
	string str;
	int id;
	int min;
	for (int i=0; i<10000; i++){
		n=i;
	}
	scanf("%d",&n);
	while (n!=0){
		scanf("\n");
		getline(cin, str);
		if (str.find('Z')!=-1){
			cout<<0<<endl;
			scanf("%d",&n);
			continue;
		}
		id=str.find_first_not_of('.');
		min=2000001;
		for (int i=id+1; i<n; i++){
			if (str[i]=='.')
				continue;
			if (str[i]==str[id]){
				id=i;
				continue;
			}
			if (i-id<min){
				min=i-id;
			}
			id=i;
		}
		cout<<min<<endl;
		scanf("%d",&n);
	}
	return 0;
}