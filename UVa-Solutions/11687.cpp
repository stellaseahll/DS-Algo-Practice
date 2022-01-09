#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

int main(){
	string str, str2;
	int i;
	cin>>str2;
	while (str2!="END"){
		i=0;
		do{
			str=str2;
			ostringstream ss;
			ss<<str.size();
			str2=ss.str();
			i++;
		}while (str!=str2);
		cout<<i<<endl;
		cin>>str2;
	}
	return 0;
}