#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <list>
using namespace std;

int main(){
	int n;
	int M,F;
	string tmp;
	scanf("%d",&n);
	getline(cin,tmp);
	vector<string> out;
	for (int i=0; i<n; i++){
		M=0;
		F=0;
		getline(cin,tmp);
		char str[tmp.length()];
		strcpy(str,tmp.c_str());
		for (int j=0; j<tmp.length(); j++){
			if (str[j]=='M')
				M++;
			else if (str[j]=='F')
				F++;
		}
		if (M==F&&F!=1)
			out.push_back("LOOP");
		else
			out.push_back("NO LOOP");
	}
	for (int i=0; i<out.size(); i++){
		cout<<out[i]<<endl;
	}

	return 0;
}