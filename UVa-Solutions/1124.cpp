#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int main(){
	string s;
	vector<string> out;
	while (getline(cin,s)){
		out.push_back(s);
	}
	for (int i=0; i<out.size(); i++){
		cout<<out[i]<<endl;
	}
	return 0;
}