#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <list>
using namespace std;

int main(){
	int k,m;
	int c,r;
	int check;
	int tmp;
	int met;
	vector<string> out;
	string str;
	scanf("%d",&k);
	while (k!=0){
		scanf("%d",&m);
		check=1;
		list<int> module;
		for (int i=0; i<k; i++){
			scanf("%d",&tmp);
			module.push_back(tmp);
		}
		for (int i=0; i<m; i++){
			if (check){
				list<int> tmpmodule=module;
				scanf("%d%d",&c,&r);
				for (int j=0; j<c; j++){
					scanf("%d",&tmp);
					tmpmodule.remove(tmp);				
				}
				met=k-tmpmodule.size();
				if (met<r){
					check=0;
					getline(cin,str);
				}
					
			}
			else{
				getline(cin,str);				
			}
		}
		if (check){
			out.push_back("yes");
		}
		else
			out.push_back("no");
		scanf("%d",&k);
	}
	for (int i=0; i<out.size(); i++){
		cout<<out[i]<<endl;
	}

	return 0;
}