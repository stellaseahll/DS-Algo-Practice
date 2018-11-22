#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	string str;
	vector<string> song;
	vector<string> name;
	song.push_back("Happy");
	song.push_back("birthday");
	song.push_back("to");
	song.push_back("you");
	for (int i=0; i<n; i++){
		cin>>str;
		name.push_back(str);
	}
	int N=ceil(n/16.0)*16;
	for (int i=0; i<N; i++){
		cout<<name[i%n]<<": ";
		if (i%16==11)
			cout<<"Rujia"<<endl;
		else
			cout<<song[i%4]<<endl;
	}
	return 0;
}