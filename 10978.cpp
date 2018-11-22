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
        vector <pair <string, int> > store;
        string card, name;
        for (int i=0; i<n; i++){
            cin>>card>>name;
            pair<string, int> p;
            p.first=card;
            p.second=name.size();
            store.push_back(p);
        }
        int order[n];
        for (int i=0; i<n; i++){
            order[i]=-1;
        }
        int curr=(store[0].second-1)%n;
        order[curr]=0;
        int fill=1;
        int tmp;
        for (int i=1; i<n; i++){
            tmp=store[i].second;
            while (tmp){
                curr++;
                curr=curr%n;
                if (order[curr]==-1){
                    tmp--;
                }
            }
            order[curr]=fill++;
        }
        for (int i=0; i<n-1; i++){
            cout<<store[order[i]].first<<" ";
        }
        cout<<store[order[n-1]].first<<endl;
        scanf("%d", &n);
    }
    return 0;
}
