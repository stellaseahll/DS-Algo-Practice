#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main(){
	int N,B,H,W;
	int p, min;
	int hs;
	int tmp;
	vector<int> out;
	string str;
	getline(cin,str);
	do{
		istringstream is(str);
		is>>N>>B>>H>>W;
		min=B+1;
		for (int i=0; i<H; i++){
			hs=0;
			cin>>p;
			for (int j=0; j<W; j++){
				cin>>tmp;
				if (tmp>=N)
					hs=1;
			}
			if (hs&& p<min)
				min=p;
		}
		if (min*N<=B)
			out.push_back(min*N);
		else
			out.push_back(-1);
		getline(cin,str);
	}while (getline(cin,str));
	for (int i=0; i<out.size(); i++){
		if (out[i]==-1)
			cout<<"stay home"<<endl;
		else
			cout<<out[i]<<endl;
	}
	return 0;
}