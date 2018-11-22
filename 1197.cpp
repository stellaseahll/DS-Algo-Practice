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

typedef pair<int,int> ii;
typedef vector<ii> vii;
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
    int N, K, M;
    int s, t;
    scanf("%d%d", &N, &K);
    while (N!=0 || K!=0){
    	UnionFind UF(N);
	    for (int i=0; i<K; i++){
	       	scanf("%d%d", &M, &s);
	       	for (int j = 1; j < M; j++){
	       		scanf("%d", &t);
	       		if (!UF.isSameSet(s,t)){
	       			UF.unionSet(s,t);
	       		}
	       	}
	    }  
	    printf("%d\n", UF.sizeOfSet(0));
	    scanf("%d%d", &N, &K);
    }
    return 0;
}