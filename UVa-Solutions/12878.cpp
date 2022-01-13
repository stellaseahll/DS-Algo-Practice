#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#include <string>
// #include <bits/stdc++.h>
#define INF 100000000
using namespace std;

typedef pair<int,int> ii; //first is the destination index, second is the cost

struct node{
	int index;
    int costFromStartToIndex;
    bool operator() (const node& lhs, const node& rhs){
        return (lhs.costFromStartToIndex>rhs.costFromStartToIndex);
    }
};
vector<vector<ii>> dijkstra(const vector<ii> *adjList, int start, int nV){
	priority_queue <node,vector<node>,node> pq;
	vector<int> dist(nV,INF); // distance from start to all vertex
	vector<vector<ii>> parents;
	for (int j = 0; j < nV; j++){
		parents.push_back(vector<ii>());
	}
	// initialize start
	node startNode;
	startNode.index = start;
	startNode.costFromStartToIndex = 0;
	dist[start] = 0;
	pq.push(startNode);
	// start dijkstra
	while (!pq.empty()){
		node currNode = pq.top();
		int currVertex = currNode.index;
		int costFromStartToCurrent = currNode.costFromStartToIndex;
		pq.pop();
		if (costFromStartToCurrent > dist[currVertex]){
			continue;
		}
		vector<ii> neighbors = adjList[currVertex];
		for (int j = 0; j < neighbors.size(); j++){
			int neighbor = neighbors[j].first;
			int costFromCurrentToNeighbor = neighbors[j].second;
			int totalCost = costFromStartToCurrent + costFromCurrentToNeighbor;
			if (totalCost < dist[neighbor]){//shorter distance, update
				parents[neighbor].clear();
				parents[neighbor].push_back(ii(currVertex,costFromCurrentToNeighbor));
				dist[neighbor] = totalCost;
				node nextNode;
				nextNode.index = neighbor;
				nextNode.costFromStartToIndex = totalCost;
				pq.push(nextNode);
			}
			else if (totalCost == dist[neighbor]){
				parents[neighbor].push_back(ii(currVertex,costFromCurrentToNeighbor));
			}
		}
	}
	return parents;
}

int main(){
    string s;
    while (getline(cin,s)){
		stringstream ss;
        ss.str(s);
        int nV, nE;
        ss >> nV >> nE;
        vector<ii> adjList[nV];
		for (int j = 0; j < nE; j++){
			int a, b, weight;
			cin >> a >> b >> weight;
			adjList[a].push_back(ii(b,weight));
            adjList[b].push_back(ii(a,weight));
		}
        vector<vector<ii>> allPaths = dijkstra(adjList,0,nV);
		queue<ii> q;
		vector<bool> isParent(nV,false);
		isParent[nV-1] = true;
		q.push(ii(nV-1,0));
		int weight = 0;
		while (!q.empty()){
			int currVertex = q.front().first;
			q.pop();
			vector<ii> currParents = allPaths[currVertex];
			for (int j = 0; j < currParents.size(); j++){
				int p = currParents[j].first;
				weight += currParents[j].second;
				if (!isParent[p]){
					isParent[p] = true;
					q.push(currParents[j]);
				}
			}
		}
		cout << weight*2 << endl;
		getline(cin,s);
        // for (int j = 0; j < s.size(); j++){
		// 	cout << "current vertex " << j << " : ";
		// 	for (int k = 0; k < s[j].size(); k++){
		// 		printf("(%d,%d), ", s[j][k].first, s[j][k].second);
		// 	}
		// 	cout << endl;
		// }
    }
    return 0;
}