#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <map>
#include <string.h>
#include <utility>
#include <cmath>
using namespace std;

// need to declare array size, other than the first one
int main()
{
    int n, c;
    int row, col, sign, count, n2;
    scanf ("%d%d", &n, &c);
    while (!(n==0 && c==0)){
        row=(n+1)/2;
        col=(n+1)/2;
        n2=floor(sqrt(c*1.0));
        count=c-n2*n2;
        if (n2%2==0){
            row=row-n2/2+1;
            col=col-n2/2;
            sign=1;
        }
        else{
            row=row+n2/2;
            col=col+n2/2;
            sign=-1;
        }
        if (count==0){
            printf("Line = %d, column = %d.\n", row, col);
            scanf("%d%d", &n, &c);
            continue;
        }
        row-=sign;
        count--;
        if (count==0){
            printf("Line = %d, column = %d.\n", row, col);
            scanf("%d%d", &n, &c);
            continue;
        }
        for (int i=0; i<n2; i++){
            if (count==0)
                break;
            col+=sign;
            count--;
        }
        for (int i=0; i<n2; i++){
            if (count==0)
                break;
            row+=sign;
            count--;
        }
        printf("Line = %d, column = %d.\n", row, col);
        scanf("%d%d", &n, &c);
    }
    return 0;
}