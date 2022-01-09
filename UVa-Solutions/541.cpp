#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <map>
#include <string.h>
#include <utility>

int main(){
    int n;
    scanf("%d",&n);
    while (n!=0){
        int bit[n][n], row[n], col[n];
        for (int i=0; i<n; i++){
            row[i]=0;
            col[i]=0;
            for (int j=0; j<n; j++){
                scanf("%d", &bit[i][j]);
            }
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                row[i]+=bit[i][j];
                col[i]+=bit[j][i];
            }
        }
        int checkRow=0, checkCol=0;
        int idxR, idxC;
        for (int i=0; i<n; i++){
            if (row[i]%2){
                checkRow++;
                idxR=i;
            }
            if (col[i]%2){
                checkCol++;
                idxC=i;
            }
            if (checkRow>1 || checkCol>1)
                break;
        }
        if (checkRow==0 && checkCol==0)
            printf("OK\n");
        else if (checkRow==1 && checkCol==1)
            printf("Change bit (%d,%d)\n", idxR+1, idxC+1);
        else
            printf("Corrupt\n");
        scanf("%d", &n);
    }
    return 0;
}