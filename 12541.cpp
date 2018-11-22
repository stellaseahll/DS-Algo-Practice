#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <map>
#include <string.h>
#include <utility>
#include <cstdlib> 
#include <algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	string name;
	int y, m, d;

	vector <pair< pair<int, int>, string> > p;
	pair< pair<int, int>, string> tmp;
	for (int i=0; i<n; i++){
		cin>>name>>d>>m>>y;
		tmp.first.first = y;
		tmp.first.second = m*100+d;
		tmp.second = name;
		p.push_back(tmp);
	}
	std::sort(p.begin(), p.end());
	cout<<p[n-1].second<<endl<<p[0].second<<endl;
}