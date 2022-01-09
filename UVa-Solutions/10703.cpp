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
    int w,h,n;
    int xmin, xmax, ymin, ymax;
    scanf("%d%d%d",&w, &h, &n);
    while (!(w==0 && h==0 && n==0)){
        if (n==0){
            if (w*h==1)
                printf("There is one empty spot.\n");
            else
                printf("There are %d empty spots.\n", w*h);
            scanf("%d%d%d",&w, &h, &n);
            continue;
        }
        int grid[w][h];
        for (int i=0; i<w; i++){
            for (int j=0; j<h; j++){
                grid[i][j]=1;
            }
        }
        for (int i=0; i<n; i++){
            scanf("%d%d%d%d", &xmin, &ymin, &xmax, &ymax);
            if (--xmin>--xmax){
                std::swap(xmin, xmax);
            }
            if (--ymin>--ymax){
                std::swap(ymin, ymax);
            }
            for (int j=xmin; j<=xmax; j++){
                for (int k=ymin; k<=ymax; k++){
                    grid[j][k]=0;
                }
            }
        }
        int count=0;
        for (int i=0; i<w; i++){
            for (int j=0; j<h; j++){
                if (grid[i][j])
                    count++;
            }
        }
        if (count==0){
            printf("There is no empty spots.\n");
        }
        else if (count==1){
            printf("There is one empty spot.\n");
        }
        else
            printf("There are %d empty spots.\n", count);
        scanf("%d%d%d",&w, &h, &n);
    }
    return 0;
}