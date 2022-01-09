#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <map>
#include <string.h>
#include <utility>
using namespace std;

int main()
{
    int n, q, t;
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        printf("Case #%d:\n", i+1);
        int question[10001];
        int p[3], winner[3], max;
        p[0]=0;
        p[1]=0;
        p[2]=0;
        for (int j=0; j<10001; j++){
            question[j]=0;
        }
        scanf("%d", &q);
        for (int j=0; j<q; j++){
            scanf("%d", &t);
            question[t]=1;
        }
        p[0]=q;
        scanf("%d", &q);
        for (int j=0; j<q; j++){
            scanf("%d", &t);
            if (question[t]==1){
                question[t]=-1;
                p[0]--;
            }                
            else{
                question[t]=2;
                p[1]++;
            }
        }
        scanf("%d", &q);
        for (int j=0; j<q; j++){
            scanf("%d", &t);
            if (question[t]==2){
                question[t]=-1;
                p[1]--;
            }  
            else if (question[t]==1){
                question[t]=-1;
                p[0]--;
            }
            else if (question[t]==0){
                question[t]=3;
                p[2]++;
            }
        }
        max = (p[0]>p[1]) ? p[0] : p[1];
        max = (max>p[2])? max : p[2];
        winner[0]=0;
        winner[1]=0;
        winner[2]=0;
        for (int j=0; j<3; j++){
            if (p[j]==max)
                winner[j]=1;
        }       
        for (int k=0; k<3; k++){
            if (!winner[k])
                continue;
            printf("%d %d", k+1, max);
            for (int j=0; j<10001; j++){
                if (question[j]==k+1){
                    printf(" %d", j);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
