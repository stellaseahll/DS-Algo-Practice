#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int main(){
	string s;
	vector<string> out;
	cin>>s;
	while (s!="*"){
		if (s=="Hajj")
			out.push_back("Hajj-e-Akbar");
		else
			out.push_back("Hajj-e-Asghar");
		cin>>s;
	}
	for (int i=0; i<out.size(); i++){
		cout<<"Case "<<i+1<<": "<<out[i]<<endl;
	}
	return 0;
}