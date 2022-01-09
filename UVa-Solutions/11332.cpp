#include <iostream>
#include <cstdio>
#include <vector>
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
	int n;
	vector<int> out;
	scanf("%d",&n);
	while (n){
		out.push_back(digitsum(n));
		scanf("%d",&n);
	}
	for (int i=0; i<out.size(); i++){
		printf("%d\n",out[i]);
	}
	return 0;
}