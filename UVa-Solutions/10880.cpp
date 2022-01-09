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
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n; 
    long  C, R;
    long  tmp;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        printf("Case #%d:", i);
        scanf("%ld%ld", &C, &R);
        if (R == C){
            printf(" 0\n");
            continue;
        }
        tmp = sqrt(C-R);
        vector < long> v;
        for (int j = 1; j <= tmp; j++){
            if ( (C-R)%j == 0 ){
                v.push_back(j);
                if (j != (C-R)/j)
                    v.push_back((C-R)/j);
            }
        }
        std::sort(v.begin(), v.end());
        for (int j = 0; j < v.size(); j++){
            if (v[j] > R){
                printf(" %ld", v[j]);
            }
        }
        printf("\n");


    }
   
}