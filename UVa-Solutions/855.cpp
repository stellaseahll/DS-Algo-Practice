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
#include <algorithm>
using namespace std;

int main()
{
    int T;
    int S, A, F;
    scanf("%d", &T);
    for (int i=0; i<T; i++){
        scanf("%d%d%d", &S, &A, &F);
        int s[F];
        int a[F];
        for (int j=0; j<F; j++){
            scanf("%d%d", &s[j], &a[j]);
        }
        std::sort(s, s+F);
        std::sort(a, a+F);
        printf("(Street: %d, Avenue: %d)\n", s[(F-1)/2], a[(F-1)/2]);
    }
    return 0;
}