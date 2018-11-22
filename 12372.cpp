#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int n;
	int x,y,z;
	scanf("%d",&n);
	vector<string> out;
	for (int i=0; i<n; i++){
		scanf("%d%d%d",&x,&y,&z);
		if (x<=20&&y<=20&&z<=20)
			out.push_back("good");
		else
			out.push_back("bad");
	}
	for (int i=0; i<n; i++){
		cout<<"Case "<<i+1<<": "<<out[i]<<endl;
	}
	return 0;
}