#include <iostream>
#include <vector>
#include <map>
#include <queue>

// #include <bits/stdc++.h>
#define MAX 1001
using namespace std;

typedef pair<int,int> ii; //first is the destination index, second is the cost

vector<int> bfs(int startVertex, int nV, vector<int>* adjList){
    vector<bool> isVisited(nV,false);
    vector<int> height(nV,-1);
    queue<ii> q;
    q.push(ii(startVertex,0));
    isVisited[startVertex] = true;
    height[startVertex] = 0;
    while (!q.empty()){
        int currHeight = q.front().second + 1;
        int currVertex = q.front().first;
        q.pop();
        vector<int> neighbors = adjList[currVertex];
        for (int j = 0; j < neighbors.size(); j++){
            int currNeighbor = neighbors[j];
            if (!isVisited[currNeighbor]){
                isVisited[currNeighbor] = true;
                height[currNeighbor] = currHeight;
                q.push(ii(currNeighbor,currHeight));
            }
        }
    }
    return height;
}
int main(){
    int x;
    cin >> x;
    int caseCount = 0;
    while (x!=0){
        int currIdx = 0;
        vector<int> adjList[MAX];
        map<int,int> m;
        int idx = 0;
        for (int j = 0 ; j < x; j++){
            int node1, node2;
            cin >> node1 >> node2;
            if (m.count(node1) == 0){
                m[node1] = idx++;
            }
            if (m.count(node2) == 0){
                m[node2] = idx++;
            }
            int v1 = m[node1], v2 = m[node2];
            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1);
        }
        int nV = idx;
        int node, distance;
        cin >> node >> distance;
        while (node != 0 || distance != 0){
            int start = m[node];
            vector<int> height = bfs(start, nV, adjList);
            int count = 0; 
            for (int j = 0; j < nV; j++){
                if (height[j] >=0 && height[j] <= distance){
                    count++;
                }
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++caseCount,nV-count, node, distance);
            cin >> node >> distance;
        }

        cin >> x;
    }
    return 0;
}