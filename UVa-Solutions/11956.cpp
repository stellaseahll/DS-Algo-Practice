#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

int main(){
	string str;
	int n;
	for (int i=0; i<1000000000; i++){
		n=i;
	}
	scanf("%d\n",&n);
	for (int i=0; i<n; i++){
		getline(cin,str);
		int A[100];
		for (int j=0; j<100; j++){
			A[j]=0;
		}
		int pointer=0;
		for (int j=0; j<str.length(); j++){
			if (str[j]=='.')
				continue;
			if (str[j]=='>'){
				pointer++;
				if (pointer>99)
					pointer-=100;
			}
			else if (str[j]=='<'){
				pointer--;
				if (pointer<0)
					pointer+=100;
			}
			else if (str[j]=='+'){
				A[pointer]++;
				if (A[pointer]>255)
					A[pointer]-=256;
			}
			else if (str[j]=='-'){
				A[pointer]--;
				if (A[pointer]<0)
					A[pointer]+=256;
			}
		}
		printf("Case %d:",i+1);
		for (int j=0; j<100; j++){
			printf(" %02X",A[j]);
		}
		printf("\n");
	}
	return 0;
}