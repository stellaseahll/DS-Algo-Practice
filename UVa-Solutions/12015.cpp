#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main(){
	int n;
	int max;
	scanf("%d",&n);
	vector<string> out;
	string tmp;
	for (int i=0; i<n; i++){
		vector<string> input;
		int rel[10];
		max=-1;
		ostringstream header;
		header<<"Case #"<<i+1<<":";
		out.push_back(header.str());
		for (int j=0; j<10; j++){
			cin>>tmp>>rel[j];
			input.push_back(tmp);
			if (rel[j]>max)
				max=rel[j];
		}
		for (int j=0; j<10; j++){
			if (rel[j]==max)
				out.push_back(input[j]);
		}

	}
	for (int i=0; i<out.size(); i++){
		cout<<out[i]<<endl;
	}
	
	return 0;
}