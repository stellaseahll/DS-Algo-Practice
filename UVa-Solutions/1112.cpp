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
    while (N--){
		if (tmp>0){
			cout << endl;
		}
		tmp++;
		int nV, nE, target, time;
        cin >> nV >> target >> time >> nE;
		target = target - 1;
		vector<ii> adjList[nV];
		for (int j = 0; j < nE; j++){
			int start, end, weight;
			cin >> start >> end >> weight;
			start = start-1;
			end = end-1;
			adjList[start].push_back(ii(end,weight));
		}
		int n = 0;
		for (int j = 0; j < nV; j++){
			vector<int> t;
			t = dijkstra(adjList,j,nV);
			if (t[target]<=time){
				n++;
			};
		}
		cout << n << endl ;

    }
    return 0;
}