#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <map>
#include <string.h>
#include <utility>
#include <cmath>
using namespace std;

// need to declare array size, other than the first one
int main()
{
    int n, t;
    char c;
    scanf ("%d", &n);
    for (int i=1; i<=n; i++){
        printf("Test #%d: ", i);
        scanf("\n%c %c",&c,&c);
        scanf("%d", &t);
        printf("\nt=%d\n", t);
        int a[t][t];
        for (int j=0; j<t; j++){
            for (int k=0; k<t; k++){
                scanf("%d", &a[j][k]);
            }
        }

    }
    return 0;
}