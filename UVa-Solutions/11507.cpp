#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <list>
using namespace std;

int main(){
	int k;
	vector<string> out;
	string curr;
	string prev;
	scanf("%d",&k);
	while (k!=0){
		prev="+x";
		for (int i=1; i<k; i++){
			cin>>curr;
			if (curr=="No")
				continue;
			else if (prev=="+x")
				prev=curr;
			else if (prev=="-x"){
				if (curr=="+y")
					prev="-y";
				else if (curr=="-y")
					prev="+y";
				else if (curr=="+z")
					prev="-z";
				else if (curr=="-z")
					prev="+z";
			}
			else if ((prev=="+y"||prev=="-y")&&(curr=="+z"||curr=="-z"))
				continue;
			else if ((prev=="+z"||prev=="-z")&&(curr=="+y"||curr=="-y"))
				continue;
			else if (prev==curr)
				prev="-x";
			else
				prev="+x";
		}
		out.push_back(prev);
		scanf("%d",&k);
	}
	for (int i=0; i<out.size(); i++){
		cout<<out[i]<<endl;
	}

	return 0;
}