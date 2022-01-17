#include <vector>
#include <iostream>
#include <istream>
#include <queue>
#include <sstream>
#include <set>
#include <algorithm>
#include <string>
// #include <bits/stdc++.h>
#define INF 1000000
using namespace std;

long findNumWays(const vector<int>& coinDenomination, int type, int money, vector<vector<long>>& memo){
    if (money == 0){
        return 1;
    }
    if (money < 0){
        return 0;
    }
    if (type == coinDenomination.size()){
        return 0;
    }
    if (memo[type][money] != -1){return memo[type][money];}
    return memo[type][money] = findNumWays(coinDenomination,type+1,money,memo) + findNumWays(coinDenomination,type,money-coinDenomination[type],memo) ;
}


int main(){
    vector<int> coinDenomination = {1,5,10,25,50};
    int money = 30000;
    vector<vector<long>> memo(5,vector<long>(money+1,-1));
    
    string s;
    while (getline(cin,s)){
        stringstream ss;
        ss << s;
        int m;
        ss >> m;
        long way = findNumWays(coinDenomination, 0, m, memo);
        if (way==1){
            printf("There is only 1 way to produce %d cents change.\n",m);
        }
        else{
            printf("There are %ld ways to produce %d cents change.\n",way,m);
        }
    }
    return 0;
}