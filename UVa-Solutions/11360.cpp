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
void transpose(int a[][MAX], int n){
    int b[n][n];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            b[i][j]=a[j][i];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            a[i][j]=b[i][j];
        }
    }  
    return; 
}

void row(int arr[][MAX], int n, int a, int b){
    for (int i=0; i<n; i++){
        std::swap(arr[a][i], arr[b][i]);
    }
    return;
}

void col(int arr[][MAX], int n, int a, int b){
    for (int i=0; i<n; i++){
        std::swap(arr[i][a], arr[i][b]);
    }
    return;
}

void inc(int a[][MAX], int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            a[i][j]++;
            a[i][j]=a[i][j]%10;
        }
    }
    return; 
}

void dec(int a[][MAX], int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            a[i][j]--;
            if (a[i][j]==-1)
                a[i][j]=9;
        }
    }
    return; 
}


int main()
{
    int N, n, t;
    int x,y;
    char c;
    string str;
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        printf("Case #%d\n", i+1);
        scanf("%d\n", &n);
        int a[MAX][MAX];
        for (int j=0; j<n; j++){
            for (int k=0; k<n; k++){
                scanf("%c",&c);
                a[j][k]=c-'0';
            }
            scanf("\n");
        }
        scanf("%d", &t);
        for (int j=0; j<t; j++){
            cin>>str;
            if (str=="transpose")
                transpose(a,n);
            else if (str=="inc")
                inc(a,n);
            else if (str=="dec")
                dec(a,n);
            else{
                scanf("%d%d", &x, &y);
                if (str=="row")
                    row(a,n,x-1,y-1);
                else
                    col(a,n,x-1,y-1);
            }
        }
        for (int j=0; j<n; j++){
            for (int k=0; k<n; k++){
                printf("%d", a[j][k]);
            }
            printf("\n");
        }        
        printf("\n");
    }

    return 0;
}