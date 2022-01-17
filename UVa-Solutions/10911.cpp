#include <vector>
#include <iostream>
#include <sstream>
#include <math.h>
#include <algorithm>
#include <string>
// #include <bits/stdc++.h>
#define INF 1000000000.0
using namespace std;
typedef pair<int,int> ii;
double memo[1 << 16]; 
double dist[16][16];

double matching(int bitmask, const int& numGroup){
    if (bitmask == ((1 << numGroup*2) - 1)){
        return 0 ; // cost for matching = 0
    }
    if (memo[bitmask] > -0.1){
        return memo[bitmask]; // already computed
    }
    int p1, p2;
    for (p1 = 0; p1 < 2*numGroup; p1++){
        if (!(bitmask & (1 << p1))){break;}
    }
    int newBitmask = bitmask | (1 << p1);
    // printf("P1: (%d,%d)\n",bitmask,newBitmask);
    double minDistance = INF;
    for (p2 = p1+1; p2 < 2*numGroup; p2++){
        if (! (newBitmask & (1 << p2))){
            double tmp = dist[p1][p2] + matching((bitmask | (1 << p1) | (1 << p2)),numGroup);
            if (tmp < minDistance){
                minDistance = tmp;
            }
        }
    }
    return memo[bitmask] = minDistance;
}
int main(){
    int N;
    int caseNo = 1;
    cin >> N;
    while (N!=0){
        for (int j = 0; j < (1 << 16); j++){
            memo[j] = -1.0;
        }
        vector<pair<double,double>> coordinates;
        // cin >> x >> y;
        for (int i = 1; i <= 2*N; i++){
            string s;
            double x,y;
            cin >> s >> x >> y;
            coordinates.push_back(pair<double,double>(x,y));
        }
        for (int j = 0; j < coordinates.size(); j++){
            for (int k = j; k < coordinates.size(); k++){
                double x1 = coordinates[j].first, y1 = coordinates[j].second;
                double x2 = coordinates[k].first, y2 = coordinates[k].second;
                dist[j][k] = dist[k][j] = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
            }
        }
        
        printf("Case %d: %.2f\n",caseNo++,matching(0, N));
        cin >> N;
    }
    
    return 0;
}