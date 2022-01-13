#include <vector>
#include <iostream>
#include <istream>
#include <queue>
#include <sstream>

#include <algorithm>
#include <string>
using namespace std;
typedef pair<int,int> ii;

vector<int> getIncreasingSequence(vector<int> v){
    int memo[v.size()], index[v.size()];
    vector<int> parent(v.size(),-1);
    int currChild = 0;
    int currSize = 1;
    memo[0] = v[0];
    index[0] = 0;
    for (int j = 1; j < v.size(); j++){
        int x = v[j];
        int idx = lower_bound(memo,memo+currSize,x) - memo;
        if (idx==currSize){//sequence became longer
            currChild = j;
            currSize++;
        }
        else if (idx==currSize-1){
            currChild = j;
        }
        if (idx>=0){
            memo[idx] = x;
            index[idx] = j;
            parent[j] = (idx==0)? -1 : index[idx-1];
        }
    }
    vector<int> answer;
    while (parent[currChild]!=-1){
        answer.push_back(v[currChild]);
        currChild = parent[currChild];
    }
    answer.push_back(v[currChild]);
    return answer;
}

int main(){
    int x;
    string s;
    vector<int> v;
    while (getline(cin,s)){
        stringstream toStream(s);
        toStream >> x;
        v.push_back(x);
    }
    vector<int> c = getIncreasingSequence(v);
    cout << c.size() << endl << "-" << endl;
    for (int j = c.size()-1; j >= 0; j--){
        cout << c[j] << endl;
    }
    return 0;
}