#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

int digitsum(int n){
	if (n<10)
		return n;
	int sum = 0;
	while (n>0){
		sum+=n%10;
		n/=10;
	}
	return digitsum(sum);
}

int main(){
	string a,b;
	int tmpa, tmpb;
	vector<double> out;
	while (getline(cin,a)){
		getline(cin,b);
		int A=0, B=0;
		for (int i=0; i<a.length(); i++){
			tmpa=int(a.at(i));
			if (tmpa>64&&tmpa<91)
				A+=tmpa-64;
			else if (tmpa>96&&tmpa<123)
				A+=tmpa-96;
		}
		for (int i=0; i<b.length(); i++){
			tmpb=int(b.at(i));
			if (tmpb>64&&tmpb<91){
				B+=tmpb-64;
			}
			else if (tmpb>96&&tmpb<123)
				B+=tmpb-96;
		}
		A=digitsum(A);
		B=digitsum(B);
		if (A>B)
			out.push_back(B*100.0/A);
		else
			out.push_back(A*100.0/B);
	}
	for (int i=0; i<out.size(); i++){
		printf("%.2f %%\n",out[i]);
	}
	return 0;
}