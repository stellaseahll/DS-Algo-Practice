#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	int a,b;
	int tmp;
	vector<int> out;
	scanf("%d%d",&a,&b);
	while (a!=-1 && b!=-1){
		tmp=abs(a-b);
		if (tmp<=100-tmp)
			out.push_back(tmp);
		else
			out.push_back(100-tmp);
		scanf("%d%d",&a,&b);
	}
	for (int i=0; i<out.size(); i++){
		printf("%d\n",out[i]);
	}
	
	
	return 0;
}