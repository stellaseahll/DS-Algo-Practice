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
    int c;
    scanf("%d", &n);
    unsigned long int p;
    for (int i=0; i<n; i++){
        vector<int> cost;
        scanf("%d", &c);
        while (c != 0){
            cost.push_back(c);
            scanf("%d", &c);
        }
        std::sort(cost.rbegin(), cost.rend());
        p = 0;
        for (int i=0; i<cost.size(); i++){
            p+=2*int (pow(cost[i], i+1));
            if (p>5000000)
                break;
        }
        if (p>5000000)
            printf("Too expensive\n");
        else
            printf("%ld\n", p);

    }
    return 0;
}