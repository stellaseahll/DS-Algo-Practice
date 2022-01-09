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
    int n;
    scanf("%d", &n);
    while (n!=0){
        int amp[n+2];
        for (int i=1; i<=n; i++){
            scanf("%d", &amp[i]);
        }
        amp[0]=amp[n];
        amp[n+1]=amp[1];
        int count=0;
        for (int i=1; i<=n; i++){
            if (amp[i]>amp[i-1] && amp[i]>amp[i+1])
                count++;
            else if (amp[i]<amp[i-1] && amp[i]<amp[i+1])
                count++;
        }
        cout<<count<<endl;
        scanf("%d",&n);
    }
    return 0;
}
