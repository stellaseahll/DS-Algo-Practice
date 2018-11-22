#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <map>
#include <string.h>
#include <utility>
#include <cstdlib> // for atoi
using namespace std;

int main()
{
    int n, s;
    int L, R;
    int l, r;
    scanf("%d%d", &n, &s);
    while (!(n==0 && s ==0)){
        int left[n+2];
        int right[n+2];
        for (int i=1; i<=n; i++){
            left[i]=i;
            right[i]=i;
        }
        left[0]=-1;
        left[n+1]=-1;
        right[0]=-1;
        right[n+1]=-1;
        for (int i=0; i<s; i++){
            scanf("%d%d", &L, &R);
            //printf("%d %d\n", L, R);
            l = left[L-1];
            if (l==-1){
                printf("*");
                left[R]=l;
                left[L]=-1;
            }
            else{
                while (left[l]!=l){
                    l=left[l];
                    if (l == -1)
                        break;
                }
                if (l == -1)
                    printf("*");
                else
                    printf("%d", l);
                left[L]=-1;
                left[R]=l;
            }
            r = right[R+1];
            if (r == -1){
                printf(" *\n");
                right[L]=r;
                right[R]=-1;
            }
            else{
                while (right[r] != r){
                    r=right[r];
                    if (r==-1)
                        break;
                }
                if (r == -1)
                    printf(" *\n");
                else
                    printf(" %d\n", r);
                right[R]=-1;
                right[L]=r;
            }
        }
        printf("-\n");
        scanf("%d%d", &n, &s);
    }
    return 0;
}