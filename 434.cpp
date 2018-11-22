#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <iomanip>
#include <map>
using namespace std;

int main()
{
    int n, d;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &d);
        int front[d], right[d], min[d][d], max[d][d];
        int minSum, maxSum, tmp;
        map <int, pair<int, int> > mymap;
        std::map <int, pair<int, int> >:: iterator it;
        for (int j = 0; j < d; j++){
            scanf("%d", &front[j]);
            it = mymap.find(front[j]);
            if (it != mymap.end())
                (it -> second).first++;
            else{
                pair<int, int> p;
                p.first=1;
                p.second=0;
                mymap.insert (std::pair<int,pair<int, int> >(front[j],p));
            }
                

        }
        for (int j = 0; j < d; j++){
            scanf("%d", &right[j]);
            it = mymap.find(right[j]);
            if (it != mymap.end())
                (it -> second).second++;
            else{
                pair<int, int> p;
                p.first=0;
                p.second=1;
                mymap.insert (std::pair<int,pair<int, int> >(right[j],p));
            }
        }
        minSum=0;
        for (it=mymap.begin(); it!=mymap.end(); it++){
            tmp = (it->second.first > it->second.second) ? it->second.first : it->second.second;
            minSum += tmp* it->first;            
        }
        for (int j=0; j<d; j++){
            for (int k=0; k<d; k++){
                min[j][k]=0;
                max[j][k]=0;
            }
        }
        for (int j=0; j<d; j++){
            for (int k=0; k<d; k++){
                if (front[j]==right[k]){
                    min[k][j]=front[j];
                    break;
                }
            }
        }
        maxSum=0;
        for (int j=0; j<d; j++){
            for (int k=0; k<d; k++){
                if (front[j]>right[k]){
                    maxSum+=right[k];
                }
                else{
                    maxSum+=front[j];
                }
                    
            }
        }
        printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n", minSum, maxSum-minSum);
    }
    return 0;
}