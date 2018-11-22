#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main(){
	string str;
	int id1, id2;
	int n;
	scanf("%d",&n);
	while (n!=0){
		getline(cin,str);
		int check[n];
		int max=0;
		for (int i=0; i<n; i++){
			getline(cin,str);
			id1=str.find_first_of(' ');
			id2=str.find_last_of(' ');
			if (id1==-1){
				max=25;
				check[i]=25;
				continue;
			}
			check[i]=id1+24-id2;
			max= (max>check[i])? max : check[i];
		}
		int count=0;
		for (int i=0; i<n; i++){
			if (check[i]<max)
				count+=max-check[i];	
		}
		cout<<count<<endl;
		scanf("%d",&n);


	}

	return 0;
}