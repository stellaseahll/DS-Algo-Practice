#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int main(){
	string s;
	vector<string> out;
	cin>>s;
	while (s!="#"){
		if (s=="HELLO")
			out.push_back("ENGLISH");
		else if (s=="HOLA")
			out.push_back("SPANISH");
		else if (s=="HALLO")
			out.push_back("GERMAN");
		else if (s=="BONJOUR")
			out.push_back("FRENCH");
		else if (s=="CIAO")
			out.push_back("ITALIAN");
		else if (s=="ZDRAVSTVUJTE")
			out.push_back("RUSSIAN");
		else
			out.push_back("UNKNOWN");
		cin>>s;
	}
	for (int i=0; i<out.size(); i++){
		cout<<"Case "<<i+1<<": "<<out[i]<<endl;
	}
	return 0;
}