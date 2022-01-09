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
int isPreserve(char left[][MAX], char right[][MAX], int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (right[i][j]!=left[i][j]){
                return 0;
            }    
        }
    }
    return 1;
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

void reflect(char a[][MAX], int n){
    char b[n][n];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            b[n-i-1][j]=a[i][j];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            a[i][j]=b[i][j];
        }
    }
}
int angle(char a[][MAX], char b[][MAX], int n){
    rotate90(a, n);
    if (isPreserve(a,b,n))
        return 90;
    rotate90(a, n);
    if (isPreserve(a,b,n))
        return 180;
    rotate90(a, n);
    if (isPreserve(a,b,n))
        return 270;
    return 0;
}

int main()
{
    string temp;
    int n, count=1, tmp;
    while (getline(cin,temp)){ // you can only getline string
        n = atoi(temp.c_str()); // to convert string to int
        char left[MAX][MAX], right[MAX][MAX]; // the function above (the parameter) will not know what is the array size, hence i put static value
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                scanf("%c", &left[i][j]);
            }
            scanf(" ");
            for (int j=0; j<n; j++){
                scanf("%c", &right[i][j]);
            }
            scanf("\n");
        }
        if (isPreserve(left, right, n)){
            printf("Pattern %d was preserved.\n", count++);
            continue;
        }
        tmp=angle(left, right, n);
        if (tmp!=0){
            printf("Pattern %d was rotated %d degrees.\n", count++, tmp);
            continue;
        }
        rotate90(left, n);
        reflect(left, n);
        if (isPreserve(left, right, n)){
            printf("Pattern %d was reflected vertically.\n", count++);
            continue;
        }
        tmp=angle(left, right, n);
        if (tmp!=0){
            printf("Pattern %d was reflected vertically and rotated %d degrees.\n", count++, tmp);
            continue;
        }
        printf("Pattern %d was improperly transformed.\n", count++);
    }
    return 0;
}