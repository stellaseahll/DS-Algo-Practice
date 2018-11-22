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
    int n, d, p, h;
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%d",&d);
        int day[d];
        for (int j=0; j<d; j++){
            day[j]=0;
        }
        scanf("%d", &p);
        for (int j=0; j<p; j++){
            scanf("%d", &h);
            for (int k=h-1; k<d; k+=h){
                day[k]++;
            }
        }
        for (int k=5; k<d; k+=7){
            day[k]=0;
            day[k+1]=0;
        }
        int sum=0;
        for (int k=0; k<d; k++){
            if (day[k]>0)
                sum++;
        }
        printf("%d\n", sum);
    }
    return 0;
}
