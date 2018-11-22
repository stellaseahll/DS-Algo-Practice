#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <iomanip>
using namespace std;

int main()
{
    int n, count=0;
    int problem[12];
    int need, sum;
    scanf("%d", &problem[0]);
    while (problem[0]!=-1){
        printf("Case %d:\n", ++count);
        for (int i=1; i<12; i++){
            scanf("%d", &problem[i]);
        }
        scanf("%d", &need);
        sum=0;
        for (int i=0; i<12; i++){
            sum+=problem[i];
            scanf("%d", &need);
            if (sum<need){
                printf("No problem. :(\n");
            }
            else{
                printf("No problem! :D\n");
                sum-=need;
            }
        }
        scanf("%d", &problem[0]);
    }
    return 0;
}
