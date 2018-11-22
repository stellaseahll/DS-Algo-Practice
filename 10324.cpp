#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

int main(){
	int n;
	int a,b;
	int k=1;
	int c;
	vector<string> out;
	string str, strtmp;
	while (getline(cin,str)){
		printf("Case %d:\n",k++);
		scanf("%d",&n);
		for (int i=0; i<n; i++){
			scanf("%d%d",&a,&b);
			if (a>b){
				swap(a,b);
			}
			c=1;
			for (int i=a+1; i<=b; i++){
				if (str[i]^str[a]){
					c=0;
					break;
				}

			}
			if (c)
				printf("Yes\n");
			else
				printf("No\n");
		}
		getline(cin,str);
	}
	return 0;
}