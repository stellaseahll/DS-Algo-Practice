#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int main(){
	string strtmp; 
	int tmp,min;
	int isSync;
	int set=0;
	while (getline(cin,strtmp)){
		set++;
		istringstream iss;
		iss.str(strtmp);
		vector<int> sig;
		while (iss>>tmp){
			sig.push_back(tmp*2);
		}
		int check[3601];
		for (int i=0; i<3601; i++){
			check[i]=0;
		}
		sort(sig.begin(),sig.end());
		min=sig[0];
		for (int i=0; i<sig.size(); i++){
			tmp=sig[i]/2-5;
			for (int j=min; j<3601; j++){
				if (j%sig[i]<tmp)
					check[j]++;
			}
		}
		isSync=0;
		for (int i=0; i<3601; i++){
			if (check[i]==sig.size()){
				cout<<"Set "<<set<<" synchs again at "<<i/60<<" minute(s) and "<<i%60<<" second(s) after all turning green."<<endl;
				isSync=1;
				break;
			}
		}
		if (!isSync)
			cout<<"Set "<<set<<" is unable to synch after one hour."<<endl;
	}
	
}