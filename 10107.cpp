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
    unsigned long int x[10000];
    int i=0;
    while (scanf("%ld", &x[i]) == 1){
        std::sort(x, x+i+1);
        // cout<<"i: "<<i<<" i/2= "<<i/2<<" i+1/2 = "<<(i+1)/2<<endl;
        // cout<<"x(i/2) = "<<x[i/2]<<"   x(i+1/2)= "<<x[(i+1)/2]<<endl;
        printf("%ld\n", (x[i/2] + x[(i+1)/2])/2);
        i++;
        scanf("\n");
    }
    return 0;
}