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

struct Segment{
    int maxFreq;
    deque<ii> pairs;
};

int max(int a,int b){
    if (b>=a){
        return b;
    }
    return a;
}
Segment merge(Segment sL, Segment sR){
    // deque<ii> tmp = sL.pairs;
    // printf("left: \n");
    // while (!tmp.empty()){
    //     printf("(%d,%d)\n", tmp.front().first, tmp.front().second);
    //     tmp.pop_front();
    // }
    // tmp = sR.pairs;
    // printf("right: \n");
    // while (!tmp.empty()){
    //     printf("(%d,%d)\n", tmp.front().first, tmp.front().second);
    //     tmp.pop_front();
    // }
    Segment merged = Segment();
    int maxFreq = max(sL.maxFreq,sR.maxFreq);
    ii midL = sL.pairs.back();
    ii midR = sR.pairs.front();
    
    if (midL.first == midR.first){
        maxFreq =  max(midL.second+midR.second,maxFreq);
        sL.pairs.pop_back();
        sR.pairs.pop_front();
        sL.pairs.push_back(ii(midL.first,midL.second+midR.second));
    }
    merged.maxFreq = maxFreq;
    while (!sR.pairs.empty()){
        sL.pairs.push_back(sR.pairs.front());
        sR.pairs.pop_front();
    }
    merged.pairs.push_back(sL.pairs.front());
    sL.pairs.pop_front();
    if (!sL.pairs.empty()){
        merged.pairs.push_back(sL.pairs.back());
    }
    return merged;
}
class SegmentTree{
    private: 
    vector<Segment> st;
    vector<int> arr;
    int n; // size of array
    int left(int p) {return (p << 1);} // given position p, return index of node left to p
    int right(int p) {return (p << 1) + 1;}

    void build(int p, int L, int R){ // O(2n) = O(1+2+4 + .. 2^logn)
        if (R==L){
            Segment s = Segment();
            s.pairs.push_back(ii(arr[L],1));
            s.maxFreq = 1;
            st[p] = s;
            return;
        }
        build(left(p), L, (L+R)/2);
        build(right(p), (L+R)/2+1, R);
        Segment sL = st[left(p)], sR = st[right(p)];
        Segment merged = merge(sL,sR);
        st[p] = merged;
        // printf("(p=%d,L=%d,R=%d)\n",p,L,R);
        // printf("maxFreq: %d\n", st[p].maxFreq);
    }

    int tp1;
    int tp2;

    Segment rangeMinQuery(int p, int L, int R, int i, int j){
        // L and R are the segments, i and j are the index to query
        if (i > R || j < L){
            return Segment();
        } // out of range
        if (L >= i && R <= j) {return st[p]; } // i,j within range 

        Segment s1 = rangeMinQuery(left(p), L, (L+R)/2, i, j);
        Segment s2 = rangeMinQuery(right(p), (L+R)/2 + 1, R, i, j);
       
       // if we access segment outside query return the right answer
        if (s1.pairs.empty()) {return s2;}  // recursive call, if one out of range, return the other
        if (s2.pairs.empty()) {return s1;}
        return merge(s1,s2); //otherwise, return min of the two
    }

    public:
        SegmentTree(const vector<int> _arr){
            arr = _arr;
            n = arr.size();
            st = vector<Segment>(4*n,Segment());
            build(1,0,n-1); // build using whole arr
        }
        int query(int i, int j){
            Segment s= rangeMinQuery(1,0,n-1,i,j);
            return s.maxFreq;
        }

};

int main(){
    int N; 
    cin >> N;
    while (N != 0){
        int nQ; 
        cin >> nQ;
        vector<int> arr(N,0);
        for (int j = 0; j < N; j++ ){
            cin >> arr[j];
        }
        SegmentTree st(arr);
        for (int j = 0; j < nQ; j++){
            int x,y;
            cin >> x >> y;
            cout << st.query(x-1,y-1) << endl;
        }
        cin >> N;
    }
    
    return 0;
}