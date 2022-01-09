#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <map>
#include <string.h>
#include <utility>
#include <cstdlib> // for atoi
#include <sstream>
#include <stack>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { numSets--; 
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main()
{
    string str;
    int N, K, M;
    int tmp1, tmp2, tmp3;
    int T, T2;
    int f;
    while (cin>>N){
        vector< pair<int, pair<int,int> > > EdgeList;
        T = 0;
        T2 =  0;
        for (int i = 1; i < N; i++){
            scanf("%d%d%d", &tmp1, &tmp2, &tmp3);
            T += tmp3;
        }
        scanf("%d", &K);
        for (int i=0; i < K; i++){
            scanf("%d%d%d", &tmp1, &tmp2, &tmp3);
            EdgeList.push_back(make_pair(tmp3, make_pair(--tmp1, --tmp2)));
        }
        scanf("%d", &M);
        for (int i=0; i < M; i++){
            scanf("%d%d%d", &tmp1, &tmp2, &tmp3);
            EdgeList.push_back(make_pair(tmp3, make_pair(--tmp1, --tmp2)));
        }
        sort(EdgeList.begin(), EdgeList.end());
        UnionFind UF(N);
        for (int i = 0; i < K+M; i++){
            pair<int, pair <int, int > > front = EdgeList[i];
            if (!UF.isSameSet(front.second.first, front.second.second)){
                T2 += front.first;
                UF.unionSet(front.second.first, front.second.second);
            }
            if (UF.numDisjointSets() == 1)
                break;
        }
        if (f){
            f = 0;
            printf("%d\n%d\n", T, T2);
        }
        else{
            printf("\n%d\n%d\n", T, T2);
        }
        
        getline(cin, str);
        getline(cin, str);
    }
    return 0;
}