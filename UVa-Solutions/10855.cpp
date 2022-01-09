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
int findRepeat(char big[][MAX], char small[][MAX], int N, int n){
    int ret=0;
    int check;
    for (int I=0; I<N-n+1; I++){
        for (int J=0; J<N-n+1; J++){
            check=1;
            for (int i=0; i<n; i++){
                for (int j=0; j<n; j++){
                    if (big[I+i][J+j]!=small[i][j]){
                        check=0;
                        break;
                    }
                }
                if (!check)
                    break;
            }
            if (check)
                ret++;
        }        
    }
    return ret;
}

void rotate90(char a[][MAX], int n){
    char b[n][n];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            b[j][n-i-1]=a[i][j];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            a[i][j]=b[i][j];
        }
    }
}


int main()
{
    int N, n, tmp;
    scanf("%d%d", &N, &n);

    while (! (N==0 && n==0)){ // you can only getline string
        char big[MAX][MAX], small[MAX][MAX]; // the function above (the parameter) will not know what is the array size, hence i put static value
        scanf("\n");
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                scanf("%c", &big[i][j]);
            }
            scanf("\n");
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                scanf("%c", &small[i][j]);
            }
            scanf("\n");
        }
        tmp=findRepeat(big, small, N, n);
        printf("%d ",tmp);
        rotate90(small, n);
        tmp=findRepeat(big, small, N, n);
        printf("%d ",tmp);  
        rotate90(small, n);
        tmp=findRepeat(big, small, N, n);
        printf("%d ",tmp);  
        rotate90(small, n);
        tmp=findRepeat(big, small, N, n);
        printf("%d\n",tmp);        
        scanf("%d%d", &N, &n);
    }
    return 0;
}