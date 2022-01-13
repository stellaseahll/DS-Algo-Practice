#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#include <string>
// #include <bits/stdc++.h>
#define MAX 1001
using namespace std;

typedef pair<int,int> ii; 

int bfs(int start, int target, int nV, vector<int>* adjList){
    queue<ii> q;
    bool isVisited[nV];
    memset(isVisited,false,sizeof(isVisited));
    isVisited[start] = true;
    q.push(ii(start,0));
    while (!q.empty()){
        int currVertex = q.front().first;
        int currHeight = q.front().second + 1;
        q.pop();
        vector<int> neighbors = adjList[currVertex];
        for (int j = 0; j < neighbors.size(); j++){
            int neighbor = neighbors[j];
            if (neighbor == target){
                return currHeight;
            }
            if (!isVisited[neighbor]){
                isVisited[neighbor] = true;
                q.push(ii(neighbor,currHeight));
            }
        }
    }
    return -1;
}
int main(){
    int N; 
    string s;
    cin >> N;
    int tmp = 0;
    getline(cin,s);
    while (N--){
        if (tmp>0){
            cout << endl;
        }
        tmp++;
        map<string,int> dictionary;
        map<int,string> index;
        string word;
        cin >> word;
        int i = 0;
        while (word!="*"){
            index[i] = word;
            dictionary[word] = i++;
            cin >> word;
        }
        vector<int> adjList[i];
        for (int j = 0; j < i; j++){
            for (int k = j+1; k < i; k++){
                string word1 = index[j], word2 = index[k];
                if (word1.size() != word2.size()){
                    continue;
                }
                int sum = 0;
                for (int l = 0; l < word1.size(); l++){
                    if (word1[l] == word2[l]){
                        sum++;
                    }
                }
                if (sum == word1.size()-1){
                    adjList[j].push_back(k);
                    adjList[k].push_back(j);
                }
            }
        }
        // for (int j = 0; j < i; j++){
        //     cout << index[j] << " -> ";
        //     for (int k = 0; k < adjList[j].size(); k++){
        //         cout << index[adjList[j][k]] << " ";
        //     }
        //     cout << endl;
        // }
        string start,target;
        getline(cin,word);
        while (getline(cin, s)){
            if (s=="\0"){
                break;
            }
            stringstream ss;
            ss.str(s);
            ss >> start >> target;
            int v1 = dictionary[start], v2 = dictionary[target];
            int distance = bfs(v1,v2,i,adjList);
            cout << start << " " << target << " " << distance << endl;
        }
    }

    return 0;
}