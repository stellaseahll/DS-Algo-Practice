#include <iostream>
#include <vector>
#include <map>
#include <queue>

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
vector<int> dijkstra(const vector<ii> *adjList, int start, int nV){
	priority_queue <node,vector<node>,node> pq;
	vector<int> dist(nV,INF); // distance from start to all vertex
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
				dist[neighbor] = totalCost;
				node nextNode;
				nextNode.index = neighbor;
				nextNode.costFromStartToIndex = totalCost;
				pq.push(nextNode);
			}
		}
	}
	return dist;
}

int main(){
    int N;
    cin >> N;
	int tmp = 0;
    int caseNo = 1;
    while (N--){
		int nV, nE, start, target;
        cin >> nV >> nE >> start >> target;
		vector<ii> adjList[nV];
		for (int j = 0; j < nE; j++){
			int a, b, weight;
			cin >> a >> b >> weight;
			adjList[a].push_back(ii(b,weight));
            adjList[b].push_back(ii(a,weight));
		}
		vector<int> t = dijkstra(adjList,start,nV);
        cout << "Case #" << caseNo++ << ": ";
        if (t[target] == INF){
            cout << "unreachable" << endl;
        }
        else{
            cout << t[target] << endl ;
        }
		

    }
    return 0;
}