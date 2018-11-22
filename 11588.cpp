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
#include <cmath>

using namespace std;

int main()
{  
    int n;
    int min, max;
    int r, c;
    scanf ("%d", &n);
    string str;
    for (int i=0; i<n; i++){
        printf("Case %d: ", i+1);
        scanf("%d%d%d%d\n", &r, &c, &max, &min);
        int store[26];
        for (int j=0; j<26; j++){
            store[j]=0;
        }
        for (int j=0; j<r; j++){
            cin >> str;
            for (int k=0; k<c; k++){
                // cout << " idx: "<< str[k]-'A';
                store[str[k]-'A']++;
            }
        }
        // for (int j=0; j<26; j++){
        //     cout<< " "<<store[j];
        // }
        // cout<<endl;
        std::sort(store, store+26);
        // for (int j=0; j<26; j++){
        //     cout<< " "<<store[j];
        // }
        // cout<<endl;
        int sum = 0;
        for (int j=25; j>=0; j--){
            if (store[j]==0)
                break;
            if (store[j]==store[25])
                sum+=max*store[j];
            else
                sum+=min*store[j];
        }
        printf("%d\n", sum);
    }
}