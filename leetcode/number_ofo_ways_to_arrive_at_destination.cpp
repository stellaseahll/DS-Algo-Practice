long long INF = 200000000000;
struct Node{
    int v; 
    long long costFromStart;
    Node(){};
    Node(int _v, long long cost){
        v = _v;
        costFromStart = cost;
    }
    bool operator()(const Node& lhs, const Node& rhs){
        return lhs.costFromStart > rhs.costFromStart;
    }
};
typedef pair<int,int> ii;
class Solution {
public:
    vector<vector<ii>> getAdjList(int n, const vector<vector<int>>& roads){
        vector<vector<ii>> adjList(n, vector<ii>{});
        for (int j = 0; j < roads.size(); j++){
            int v1 = roads[j][0];
            int v2 = roads[j][1];
            int weight = roads[j][2];
            adjList[v1].push_back(ii(v2,weight));
            adjList[v2].push_back(ii(v1,weight));
        }
        return adjList;
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<ii>> adjList = getAdjList(n,roads);
        priority_queue<Node,vector<Node>,Node> q;
        vector<long long> distance(n,INF);
        vector<long long> numWays(n,1);
        distance[0] = 0;
        numWays[0] = 1;
        Node start(0,0);
        q.push(start);
        while (!q.empty()){
            int curr = q.top().v;
            long long distFromStartToCurr = q.top().costFromStart;
            q.pop();
            if (distFromStartToCurr > distance[curr]){continue;}
            vector<ii> neighbors = adjList[curr];
            for (int j = 0; j < neighbors.size(); j++){
                int neighbor = neighbors[j].first;
                int costFromCurrToNeighbor = neighbors[j].second;
                long long totalCost = distFromStartToCurr + costFromCurrToNeighbor;
                if (totalCost < distance[neighbor]){
                    distance[neighbor] = totalCost;
                    numWays[neighbor] = numWays[curr];
                    q.push(Node(neighbor,totalCost));
                }
                else if (totalCost == distance[neighbor]){
                    numWays[neighbor] += numWays[curr];
                    numWays[neighbor] = numWays[neighbor] % 1000000007;
                }
            }
        }
        return numWays[n-1];
    }
};