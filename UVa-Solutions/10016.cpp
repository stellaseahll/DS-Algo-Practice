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
#define MAX 1000
using namespace std;

// need to declare array size, other than the first one
void flipDiagonal(int a[][MAX], int n, int r){
    for (int i=r; i<n-r; i++){
        std::swap(a[r][i], a[i][r]);
    }
    for (int i=r+1; i<n-r; i++){
        std::swap(a[n-r-1][i], a[i][n-r-1]);
    }
    return;
}
void flipInverseDiagonal(int a[][MAX], int n, int r){
    for (int i=r; i<n-r; i++){
        std::swap(a[r][i], a[n-1-i][n-r-1]);
    }
    for (int i=r; i<n-r-1; i++){
        std::swap(a[n-r-1][i], a[n-1-i][r]);
    }
    return;
}
void upsideDown(int a[][MAX], int n, int r){
    for (int i=r+1; i<n/2; i++){
        std::swap(a[i][r], a[n-1-i][r]);
        std::swap(a[i][n-1-r], a[n-1-i][n-1-r]);
    }
    for (int i=r; i<n-r; i++){
        std::swap(a[r][i], a[n-1-r][i]);
    }
    return;
}
void leftRight(int a[][MAX], int n, int r){
    for (int i=r+1; i<n/2; i++){
        std::swap(a[r][i], a[r][n-1-i]);
        std::swap(a[n-1-r][i], a[n-1-r][n-1-i]);
    }
    for (int i=r; i<n-r; i++){
        std::swap(a[i][r], a[i][n-1-r]);
    }
    return;
}


int main()
{
    int M, n, t, c, tmp;
    scanf("%d", &M);
    for (int i=0; i<M; i++){
        scanf("%d", &n);
        int a[MAX][MAX];
        for (int j=0; j<n; j++){
            for (int k=0; k<n; k++){
                scanf("%d", &a[j][k]);
            }
        }
        c=0;
        for (int j=1; j<=(n+1)/2; j++){
            scanf("%d", &t);
            for (int k=0; k<t; k++){
                scanf("%d", &tmp);
                if (tmp==1)
                    upsideDown(a,n,c);
                else if (tmp==2)
                    leftRight(a,n,c);
                else if (tmp==3)
                    flipDiagonal(a,n,c);
                else if (tmp==4)
                    flipInverseDiagonal(a,n,c);
            }
            c++;
        }
        for (int j=0; j<n; j++){
            printf("%d", a[j][0]);
            for (int k=1; k<n; k++){
                printf(" %d", a[j][k]);
            }
            printf("\n");
        }
    }
    return 0;
}