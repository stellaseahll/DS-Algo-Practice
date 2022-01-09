#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

int main(){
	int n,k;
	int t;
	int mile, juice;
	scanf("%d",&n);
	vector<string> out;
	for (int i=0; i<n; i++){
		scanf("%d",&k);
		mile=0;
		juice=0;
		for (int j=0; j<k; j++){
			scanf("%d",&t);
			if (t%30)
				mile+=ceil(t/30.0)*10;
			else
				mile+=(t/30+1)*10;
			if (t%60)
				juice+=ceil(t/60.0)*15;
			else
				juice+=(t/60+1)*15;
		}
		ostringstream tmp;
		tmp<<"Case "<<i+1<<": ";
		if (mile<juice)
			tmp<<"Mile "<<mile;
		else if (juice<mile)
			tmp<<"Juice "<<juice;
		else
			tmp<<"Mile Juice "<<mile;
		out.push_back(tmp.str());
	}
	for (int i=0; i<out.size(); i++){
		cout<<out[i]<<endl;
	}
	
	return 0;
}