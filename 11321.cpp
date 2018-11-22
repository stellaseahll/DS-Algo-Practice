#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <map>
#include <string.h>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    int N, M;
    long int n;
    scanf("%d%d", &N, &M);
    while (!(N==0 && M==0)){
        vector<pair<pair<long int, long int>, long int> > p;
        pair<pair<long int, long int>, long int> tmp;
        for (int i=0; i<N; i++){
            scanf("%ld", &n);
            tmp.first.first = -n%M;
            if (n%2 == 0){
                tmp.first.second = 0;
                tmp.second = -n;
            }
            else{
                tmp.first.second = 1;
                tmp.second = n;
            }
            p.push_back(tmp);
        }
        std:: sort(p.rbegin(), p.rend());
        printf("%d %d\n", N, M);
        for (int i=0; i<N; i++){
            if (p[i].first.second == 0)
                printf("%ld\n", -p[i].second);
            else
                printf("%ld\n", p[i].second);
        }
        scanf("%d%d", &N, &M);
    }
    printf("%d %d\n", N, M);
    return 0;
}