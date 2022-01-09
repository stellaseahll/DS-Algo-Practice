#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;


int main(){
	int n;
	char s[10000];
	scanf("%d",&n);
	char out[n];
	for (int i=0; i<n; i++){
		scanf("%s",s);
		int l=strlen(s);
		if (!(strcmp(s,"1")*strcmp(s,"4")*strcmp(s,"78")))
			out[i]='+';
		else if (s[l-2]=='3'&&s[l-1]=='5')
			out[i]='-';
		else if (s[0]=='9'&&s[l-1]=='4')
			out[i]='*';
		else
			out[i]='?';
	}
	for (int i=0; i<n; i++){
		printf("%c\n",out[i]);
	}
	return 0;
}