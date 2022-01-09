#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
	int n; 
	int c,t,w;
	char tmpC;
	scanf ("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d%d", &c, &t);
		//printf("Test %d: c= %d, t= %d\n", i, c, t);
		int equal[c];
		vector<pair <int, int> >  tmpVec, tmpVec2;
		pair <int, int> p;
		p.first=0; 
		for (int j=0; j<c; j++){
			p.second=j;
			equal[j]=0;
			tmpVec.push_back(p);
			tmpVec2.push_back(p);
		}
		for (int j=0; j<t; j++){
			scanf("%d",&w);
			int tmpA[w][2];
			for (int k=0; k<w; k++){
				scanf("%d", &tmpA[k][0]);
				tmpA[k][0]--;
				
			}
			for (int k=0; k<w; k++){
				scanf("%d", &tmpA[k][1]);
				tmpA[k][1]--;
			}
			scanf("\n%c",&tmpC);
			if (tmpC=='='){
				for (int k=0; k<w; k++){
					equal[tmpA[k][0]]=1;
					equal[tmpA[k][1]]=1;
				}
			}
			else if (tmpC=='<'){
				for (int k=0; k<w; k++){
					tmpVec[tmpA[k][0]].first++;
					tmpVec2[tmpA[k][1]].first++;
				}
			}
			else{
				for (int k=0; k<w; k++){
					tmpVec2[tmpA[k][0]].first++;
					tmpVec[tmpA[k][1]].first++;
				}
			}
		}
		int coinFound = 0;
		int id;
		for (int j=0; j<c; j++){
			if (equal[j]==0){
				coinFound++;
				id=j;
			}
			else{
				tmpVec[j].first=0;
				tmpVec2[j].first=0;
			}
		}
		if (coinFound==1){
			printf("%d",id+1);
		} 
		else{
			sort(tmpVec.rbegin(), tmpVec.rend());
			sort(tmpVec2.rbegin(), tmpVec2.rend());
			if (tmpVec[1].first==0){
				printf("0");
			}
			else if (tmpVec[0].first == tmpVec[1].first){
				printf("0");
			}
			else if (tmpVec[0].first == tmpVec[1].first || tmpVec2[0].first == tmpVec2[0].first){
				printf("0");
			}
			else if (tmpVec[0].first>tmpVec2[0].first){
				printf("%d",tmpVec[0].second+1);
			}
			else if (tmpVec2[0].first>tmpVec[0].first){
				printf("%d",tmpVec2[0].second+1);
			}
			else {
				printf("0");
			}
		}
		if (i<n-1){
			printf("\n\n");
		}
		else
			printf("\n");
	}
	return 0;
}