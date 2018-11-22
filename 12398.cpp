#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <map>
#include <string.h>
#include <utility>
#include <cstdlib> 
using namespace std;

int main()
{
    string str;
    int n=1;
    while (getline(cin,str)){
        int a[3][3];
        memset(a,0,sizeof(a));
        for (int i=str.size()-1; i>=0; i--){
            if (str[i]=='a'){
                a[0][0]=1+a[0][0];
                a[0][1]=1+a[0][1];
                a[1][0]=1+a[1][0];
            }
            else if (str[i]=='b'){
                a[0][0]=1+a[0][0];
                a[0][1]=1+a[0][1];
                a[0][2]=1+a[0][2];
                a[1][1]=1+a[1][1];
            }
            else if (str[i]=='c'){
                a[0][2]=1+a[0][2];
                a[0][1]=1+a[0][1];
                a[1][2]=1+a[1][2];
            }
            else if (str[i]=='d'){
                a[1][0]=1+a[1][0];
                a[0][0]=1+a[0][0];
                a[2][0]=1+a[2][0];
                a[1][1]=1+a[1][1];
            }
            else if (str[i]=='e'){
                a[1][1]=1+a[1][1];
                a[1][0]=1+a[1][0];
                a[1][2]=1+a[1][2];
                a[0][1]=1+a[0][1];
                a[2][1]=1+a[2][1];
            }
            else if (str[i]=='f'){
                a[1][2]=1+a[1][2];
                a[1][1]=1+a[1][1];
                a[2][2]=1+a[2][2];
                a[0][2]=1+a[0][2];
            }
            else if (str[i]=='g'){
                a[2][0]=1+a[2][0];
                a[1][0]=1+a[1][0];
                a[2][1]=1+a[2][1];
            }
            else if (str[i]=='h'){
                a[2][1]=1+a[2][1];
                a[2][2]=1+a[2][2];
                a[2][0]=1+a[2][0];
                a[1][1]=1+a[1][1];
            }
            else if (str[i]=='i'){
                a[2][2]=1+a[2][2];
                a[2][1]=1+a[2][1];
                a[1][2]=1+a[1][2];
            }
        }
        printf("Case #%d:\n", n++);
        for (int i=0; i<3; i++){
            printf("%d", a[i][0]%10);
            for (int j=1; j<3; j++){
                printf(" %d", a[i][j]%10);
            }
            printf("\n");
        }
    }
    return 0;
}