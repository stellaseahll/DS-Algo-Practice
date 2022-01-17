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

class DisjointSet{
    private: 
    int size;
    vector<int> s;

    public:
    DisjointSet(int _size){
        size = _size;
        s = vector<int>(size,-1);
    }
    int find(int v){
        if (s[v]<0){return v;}
        return s[v] = find(s[v]);
    }
    void join(int v1, int v2){
        if (v1==v2){return;}
        if (s[v1] < s[v2]){ // v1 is parent
            s[v2] = v1;
            return;
        }
        if (s[v1] == s[v2]){s[v2]--;} // make v2 the parent
        s[v1] = v2;
        return;
    }

};

int main(){
    int N; 
    string s;
    int n;
    cin >> N;
    cin >> n;
    getline(cin,s);
    for (int j = 0; j < N ; j++){
        int success = 0, noSuccess=0;
        DisjointSet ds(n);
        
        // cin >> s;
        // cout<< n << " " << s  << endl;
        int k = 1;
        while (getline(cin,s)){
            if (s.empty()){
                break;
            }
            stringstream ss;
            ss << s;
            char c;
            int x,y;
            ss >> c >> x >> y;
            // cout << c << " "<< x<< " "<< y<<endl;
            int v1 = ds.find(x-1);
            int v2 = ds.find(y-1);
            // printf("(%d,%d)\n",v1,v2);
            if (c == 'c'){
                ds.join(v1,v2);
            }
            else if (c == 'q'){
                if (v1==v2){success++;}
                else{noSuccess++;}
            }
        }
        if (j==N-1){
            printf("%d,%d",success,noSuccess);
        }
        else{
            printf("%d,%d\n\n",success,noSuccess);
        }
        
        cin >>n;
        getline(cin,s);
    }
    return 0;
}