#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <map>
#include <string.h>
#include <utility>
using namespace std;

int main()
{
    int n,t;
    int sum, idx;
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d", &t);
        int have[2*t], need[2*t], net[2*t];
        for (int j=0; j<t; j++){
            scanf("%d", &have[j]);
            have[j+t]=have[j];
        }
        for (int j=0; j<t; j++){
            scanf("%d", &need[j]);
            need[j+t]=need[j];
        }
        for (int j=0; j<2*t; j++){
            net[j]=have[j]-need[j];
        }
        sum=0;
        for (int j=0; j<t; j++){
            sum += net[j];
        }
        if (sum<0){
            cout<<"Case "<<i+1<<": Not possible"<<endl;
            continue;
        }
        sum=0;
        idx=-1;
        for (int j=0; j<2*t; j++){
            sum += net[j];
            if (sum<0){
                idx=j+1;
                sum=0;
            }
        }
        cout<<"Case "<<i+1<<": Possible from station "<<(idx%t)+1<<endl;
    }
    return 0;
}
