#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int main(){
	vector<string> out;
	int x,y;
	int xtmp, ytmp;
	int n;
	scanf("%d",&n);
	while (n!=0){
		scanf("%d%d",&x,&y);
		for (int i=0; i<n; i++){
			scanf("%d%d", &xtmp, &ytmp);
			if (xtmp==x||ytmp==y)
				out.push_back("divisa");
			else if ((xtmp-x<0) && (ytmp-y<0))
				out.push_back("S0");
			else if ((xtmp-x>0) && (ytmp-y>0))
				out.push_back("NE");
			else if ((xtmp-x>0) && (ytmp-y<0))
				out.push_back("SE");
			else
				out.push_back("N0");
		}
		scanf("%d",&n);
	}
	for (int i=0; i<out.size(); i++){
		cout<<out[i]<<endl;
	}
	return 0;
}