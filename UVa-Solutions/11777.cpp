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
    int n;
    scanf("%d", &n);
    int quiz[3];
    int a,b,c,d;
    double sum;
    for (int i=0; i<n; i++){    

        scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &quiz[0], &quiz[1], &quiz[2]);
        std::sort(quiz, quiz+3);
        sum = a+b+c+d+(quiz[2]+quiz[1])/2.0;
        printf("Case %d: ", i+1);
        if (sum >= 90)
            printf("A\n");
        else if (sum>= 80)
            printf("B\n");
        else if (sum >= 70)
            printf("C\n");
        else if (sum >= 60)
            printf("D\n");
        else
            printf("F\n");
    }
    return 0;
}