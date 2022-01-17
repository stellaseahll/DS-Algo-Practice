#include <vector>
#include <iostream>
#include <istream>
#include <queue>
#include <sstream>
#include <map>
#include <algorithm>
#include <string>
// #include <bits/stdc++.h>
#define INF 1000000
using namespace std;
typedef pair<int,int> ii;

int increasingSequence(vector<int> x){
    vector<int> parent(x.size(),-1);
    vector<int> memo, index;
    memo.push_back(x[0]); // memo of current increasing sequence
    index.push_back(0); // index of element
    int currChild = 0;
    for (int j = 1; j < x.size(); j++){
        int curr = x[j];
        int idx = lower_bound(memo.begin(),memo.end(),curr) -  memo.begin();
        if (idx == memo.size()){ // add on to current list
            memo.push_back(curr);
            index.push_back(j);
            parent[j] = index[idx-1];
            currChild = j;
        }
        else if (idx >= 0){
            memo[idx] = curr;
            index[idx]  = j;
            parent[j] = (idx==0) ? -1 : index[idx-1]; // new parent if idx = 0 (smallest)
        }
    }
    int count = 1;
    while (parent[currChild]!=-1){
        count++;
        currChild = parent[currChild];
    }
    return count;
}


vector<int> getSequence(map<int,int> *m){
    int lx = m[0].size(), ly = m[1].size();
    int idx = (lx<ly) ? 0 : 1;
    vector<int> answer(m[idx].size(),-1);
    map<int,int>::iterator it;
    for (it = m[idx].begin(); it != m[idx].end(); it++){
        if (m[1-idx].count((*it).first)!=0){
            answer[(*it).second] = m[1-idx][(*it).first];
        }
    }
    return answer;
}

// int commonJumps(vector<int> x, vector<int> y){
//     int numRow = x.size()+1, numCol = y.size()+1;
//     int memo[2][numCol];
//     // ii parent[numRow][numCol];
//     memset(memo,0,sizeof(memo));
//     int bi;
//     for (int j = 0; j < numRow; j++){
//         bi = j & 1;
//         for (int k = 0 ; k < numCol; k++){
//             if (j == 0 || k == 0){
//                 memo[bi][k] = 0;
//             }
//             else if (x[j-1] == y[k-1]){
//                 memo[bi][k] = memo[1-bi][k-1] + 1;
//             }
//             else{
//                 memo[bi][k] = (memo[1-bi][k] > memo[bi][k-1])? memo[1-bi][k] : memo[bi][k-1];
//             }
//         }
//     }
//     return memo[bi][numCol-1];
// }

int main(){
    int N;
    cin >> N;
    // cin >> x >> y;
    for (int i = 1; i <= N; i++){
        int size, xSize, ySize;
        map<int,int> xyMap[2];
        scanf("%d%d%d",&size,&xSize,&ySize);
        for (int j = 0; j < xSize+1; j++){
            int tmp;
            scanf("%d",&tmp);
            xyMap[0][tmp] = j;
        }
        for (int j = 0; j < ySize+1; j++){
            int tmp;
            scanf("%d",&tmp);
            xyMap[1][tmp] = j;
        }
        vector<int> sequence = getSequence(xyMap);
        printf("Case %d: %d\n", i, increasingSequence(sequence));
    }
    return 0;
}