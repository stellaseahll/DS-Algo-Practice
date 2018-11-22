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
#define MAX 100
using namespace std;

void battle(int a[][MAX], int r, int c, int n){
    int b[r][c];
   memset(b,0,sizeof(b));

    for (int i=1; i<r-1; i++){
        for (int j=1; j<c-1; j++){
            if (a[i][j]==0){
                if (a[i+1][j]==n-1 || a[i-1][j]==n-1 || a[i][j+1]==n-1 || a[i][j-1]==n-1)
                    b[i][j]=n-1;
                else
                    b[i][j]=a[i][j];
            }
            else{
                if (a[i][j]-a[i+1][j]==1 || a[i][j]-a[i-1][j]==1 || a[i][j]-a[i][j+1]==1 || a[i][j]-a[i][j-1]==1)
                    b[i][j]=a[i][j]-1;
                else
                    b[i][j]=a[i][j];
            }
        }
    }
    if (a[0][0]==0){
        if (a[1][0]==n-1 || a[0][1]==n-1)
            b[0][0]=n-1;
        else
            b[0][0]=a[0][0];
    }
    else{
        if (a[0][0]-a[1][0]==1 || a[0][0]-a[0][1]==1)
            b[0][0]=a[0][0]-1;
        else
            b[0][0]=a[0][0];
    }
    if (a[r-1][0]==0){
        if (a[r-2][0]==n-1 || a[r-1][1]==n-1)
            b[r-1][0]=n-1;
        else
            b[r-1][0]=a[r-1][0];
    }
    else{
        if (a[r-1][0]-a[r-2][0]==1 || a[r-1][0]-a[r-1][1]==1)
            b[r-1][0]=a[r-1][0]-1;
        else
            b[r-1][0]=a[r-1][0];

    }
    if (a[0][c-1]==0){
        if (a[0][c-2]==n-1 || a[1][c-1]==n-1)
            b[0][c-1]=n-1;
        else
            a[0][c-1]=a[0][c-1];
    }
    else{
        if (a[0][c-1]-a[1][c-1]==1 || a[0][c-1]-a[0][c-2]==1)
            b[0][c-1]=a[0][c-1]-1;
        else
            b[0][c-1]=a[0][c-1];

    }
    if (a[r-1][c-1]==0){
        if (a[r-1][c-2]==n-1 || a[r-2][c-1]==n-1)
            b[r-1][c-1]=n-1;
        else
            b[r-1][c-1]=a[r-1][c-1];

    }
    else{
        if (a[r-1][c-1]-a[r-2][c-1]==1 || a[r-1][c-1]-a[r-1][c-2]==1)
            b[r-1][c-1]=a[r-1][c-1]-1;
        else
            b[r-1][c-1]=a[r-1][c-1];

    }
    for (int i=1; i<r-1; i++){
        if (a[i][0]==0){
            if (a[i+1][0]==n-1 || a[i-1][0]==n-1 || a[i][1]==n-1 )
                b[i][0]=n-1;
            else
                b[i][0]=a[i][0];
        }
        else{
            if (a[i][0]-a[i+1][0]==1 || a[i][0]-a[i-1][0]==1 || a[i][0]-a[i][1]==1)
                b[i][0]=a[i][0]-1;
            else
                b[i][0]=a[i][0];
        }
        if (a[i][c-1]==0){
            if (a[i+1][c-1]==n-1 || a[i-1][c-1]==n-1 || a[i][c-2]==n-1 )
                b[i][c-1]=n-1;
            else
                b[i][c-1]=a[i][c-1];
        }
        else{
            if (a[i][c-1]-a[i+1][c-1]==1 || a[i][c-1]-a[i-1][c-1]==1 || a[i][c-1]-a[i][c-2]==1)
                b[i][c-1]=a[i][c-1]-1;
            else
                b[i][c-1]=a[i][c-1];
        }
    }
    for (int j=1; j<c-1; j++){
        if (a[0][j]==0){
            if (a[1][j]==n-1 || a[0][j+1]==n-1 || a[0][j-1]==n-1)
                b[0][j]=n-1;
            else
                b[0][j]=a[0][j];
        }
        else{
            if (a[0][j]-a[1][j]==1 || a[0][j]-a[0][j+1]==1 || a[0][j]-a[0][j-1]==1)
                b[0][j]=a[0][j]-1;
            else
                b[0][j]=a[0][j];
        }
        if (a[r-1][j]==0){
            if (a[r-2][j]==n-1 || a[r-1][j+1]==n-1 || a[r-1][j-1]==n-1)
                b[r-1][j]=n-1;
            else
                b[r-1][j]=a[r-1][j];
        }
        else{
            if (a[r-1][j]-a[r-2][j]==1 || a[r-1][j]-a[r-1][j+1]==1 || a[r-1][j]-a[r-1][j-1]==1)
                b[r-1][j]=a[r-1][j]-1;
            else
                b[r-1][j]=a[r-1][j];
        }
    }
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            a[i][j]=b[i][j];
        }
    }    
    return; 
}



int main()
{
    int n, r, c, k;
    scanf("%d %d %d %d", &n, &r, &c, &k);
    while (!(n==0 && r==0 && c==0 && k==0)){
        int t[MAX][MAX];
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
#define MAX 100
using namespace std;

void battle(int a[][MAX], int r, int c, int n){
    int b[r][c];
    memset(b,0,sizeof(b));

    for (int i=1; i<r-1; i++){
        for (int j=1; j<c-1; j++){
            if (a[i][j]==0){
                if (a[i+1][j]==n-1 || a[i-1][j]==n-1 || a[i][j+1]==n-1 || a[i][j-1]==n-1)
                    b[i][j]=n-1;
                else
                    b[i][j]=a[i][j];
            }
            else{
                if (a[i][j]-a[i+1][j]==1 || a[i][j]-a[i-1][j]==1 || a[i][j]-a[i][j+1]==1 || a[i][j]-a[i][j-1]==1)
                    b[i][j]=a[i][j]-1;
                else
                    b[i][j]=a[i][j];
            }
        }
    }
    if (a[0][0]==0){
        if (a[1][0]==n-1 || a[0][1]==n-1)
            b[0][0]=n-1;
        else
            b[0][0]=a[0][0];
    }
    else{
        if (a[0][0]-a[1][0]==1 || a[0][0]-a[0][1]==1)
            b[0][0]=a[0][0]-1;
        else
            b[0][0]=a[0][0];
    }
    if (a[r-1][0]==0){
        if (a[r-2][0]==n-1 || a[r-1][1]==n-1)
            b[r-1][0]=n-1;
        else
            b[r-1][0]=a[r-1][0];
    }
    else{
        if (a[r-1][0]-a[r-2][0]==1 || a[r-1][0]-a[r-1][1]==1)
            b[r-1][0]=a[r-1][0]-1;
        else
            b[r-1][0]=a[r-1][0];

    }
    if (a[0][c-1]==0){
        if (a[0][c-2]==n-1 || a[1][c-1]==n-1)
            b[0][c-1]=n-1;
        else
            a[0][c-1]=a[0][c-1];
    }
    else{
        if (a[0][c-1]-a[1][c-1]==1 || a[0][c-1]-a[0][c-2]==1)
            b[0][c-1]=a[0][c-1]-1;
        else
            b[0][c-1]=a[0][c-1];

    }
    if (a[r-1][c-1]==0){
        if (a[r-1][c-2]==n-1 || a[r-2][c-1]==n-1)
            b[r-1][c-1]=n-1;
        else
            b[r-1][c-1]=a[r-1][c-1];

    }
    else{
        if (a[r-1][c-1]-a[r-2][c-1]==1 || a[r-1][c-1]-a[r-1][c-2]==1)
            b[r-1][c-1]=a[r-1][c-1]-1;
        else
            b[r-1][c-1]=a[r-1][c-1];

    }
    for (int i=1; i<r-1; i++){
        if (a[i][0]==0){
            if (a[i+1][0]==n-1 || a[i-1][0]==n-1 || a[i][1]==n-1 )
                b[i][0]=n-1;
            else
                b[i][0]=a[i][0];
        }
        else{
            if (a[i][0]-a[i+1][0]==1 || a[i][0]-a[i-1][0]==1 || a[i][0]-a[i][1]==1)
                b[i][0]=a[i][0]-1;
            else
                b[i][0]=a[i][0];
        }
        if (a[i][c-1]==0){
            if (a[i+1][c-1]==n-1 || a[i-1][c-1]==n-1 || a[i][c-2]==n-1 )
                b[i][c-1]=n-1;
            else
                b[i][c-1]=a[i][c-1];
        }
        else{
            if (a[i][c-1]-a[i+1][c-1]==1 || a[i][c-1]-a[i-1][c-1]==1 || a[i][c-1]-a[i][c-2]==1)
                b[i][c-1]=a[i][c-1]-1;
            else
                b[i][c-1]=a[i][c-1];
        }
    }
    for (int j=1; j<c-1; j++){
        if (a[0][j]==0){
            if (a[1][j]==n-1 || a[0][j+1]==n-1 || a[0][j-1]==n-1)
                b[0][j]=n-1;
            else
                b[0][j]=a[0][j];
        }
        else{
            if (a[0][j]-a[1][j]==1 || a[0][j]-a[0][j+1]==1 || a[0][j]-a[0][j-1]==1)
                b[0][j]=a[0][j]-1;
            else
                b[0][j]=a[0][j];
        }
        if (a[r-1][j]==0){
            if (a[r-2][j]==n-1 || a[r-1][j+1]==n-1 || a[r-1][j-1]==n-1)
                b[r-1][j]=n-1;
            else
                b[r-1][j]=a[r-1][j];
        }
        else{
            if (a[r-1][j]-a[r-2][j]==1 || a[r-1][j]-a[r-1][j+1]==1 || a[r-1][j]-a[r-1][j-1]==1)
                b[r-1][j]=a[r-1][j]-1;
            else
                b[r-1][j]=a[r-1][j];
        }
    }
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            a[i][j]=b[i][j];
        }
    }    
    return; 
}



int main()
{
    int n, r, c, k;
    scanf("%d %d %d %d", &n, &r, &c, &k);
    while (!(n==0 && r==0 && c==0 && k==0)){
        int t[MAX][MAX];
        memset(t,0,sizeof(t));
        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++){
                scanf("%d", &t[i][j]);
            }
        }
        for (int i=0; i<k; i++){
            battle(t,r,c,n);
        }
        for (int i=0; i<r; i++){
            printf("%d", t[i][0]);
            for (int j=1; j<c; j++) {
                printf(" %d", t[i][j]);
            }
            printf("\n");
        }
        scanf("%d %d %d %d", &n, &r, &c, &k);
    }    

    return 0;
}
        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++){
                scanf("%d", &t[i][j]);
            }
        }
        for (int i=0; i<k; i++){
            battle(t,r,c,n);
        }
        for (int i=0; i<r; i++){
            printf("%d", t[i][0]);
            for (int j=1; j<c; j++) {
                printf(" %d", t[i][j]);
            }
            printf("\n");
        }
        scanf("%d %d %d %d", &n, &r, &c, &k);
    }    

    return 0;
}