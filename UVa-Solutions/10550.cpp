#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int convert(int x){
 	while (x<0)
 		x=x+360;
 	return x;
}

int main(){
	int a,b,c,d;
	vector<int> out;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	do{	
		out.push_back(1080+convert(a*9-b*9)+convert(c*9-b*9)+convert(c*9-d*9));
		scanf("%d%d%d%d",&a,&b,&c,&d);
	}while ((a+b+c+d)!=0);
	for (int i=0; i<out.size(); i++){
		printf("%d\n",out[i]);
	}
	return 0;
}