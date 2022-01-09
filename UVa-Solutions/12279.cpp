#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int n, x;
	int c1, c2;
	vector<int> out;
	scanf("%d",&n);
	while (n!=0){
		c1=0; c2=0;
		for (int i=0; i<n; i++){
			scanf("%d",&x);
			if (x)
				c1++;
			else
				c2++;
		}
		out.push_back(c1-c2);
		scanf("%d",&n);
	}
	for (int i=0; i<out.size(); i++){
		cout<<"Case "<<i+1<<": ";
		printf("%d\n",out[i]);
	}
	return 0;
}