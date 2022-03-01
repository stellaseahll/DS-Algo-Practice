typedef pair<int,int> ii;
int INF = 2000000000;
struct Node{
    int v; 
    int costFromStart;
    int hops;
    Node(){};
    Node(int _v, int _cost, int _hops){
        v = _v;
        costFromStart = _cost;
        hops = _hops;
    }
    bool operator() (const Node& lhs, const Node& rhs){
        if (lhs.costFromStart == rhs.costFromStart){
            return lhs.hops > rhs.hops;
        }
        return lhs.costFromStart > rhs.costFromStart;
    }
};

class Solution {
public:
    vector<vector<ii>> getAdjList(int n, const vector<vector<int>>& flights){
        vector<vector<ii>> adjList(n, vector<ii>{});
        for (int j = 0; j < flights.size(); j++){
            int x = flights[j][0];
            int y = flights[j][1];
            int w = flights[j][2];
            adjList[x].push_back(ii(y,w));
        }
        return adjList;
    }
    
    int dijkstra(int n, int src, int dst, int k, const vector<vector<ii>>& adjList){
        priority_queue<Node,vector<Node>,Node> pq;
        pq.push(Node(src,0,0));
        
        vector<vector<int>> dist(k+1, vector<int>(n,INF));
        dist[0][src] = 0;

        while (!pq.empty()){
            Node currNode = pq.top();
            pq.pop();
            int costFromStartToCurr = currNode.costFromStart;
            int nhop = currNode.hops;
            int curr = currNode.v;
            if (nhop >= k){continue;}
            if (dist[nhop][curr] < costFromStartToCurr){continue;}
            vector<ii> neighbors = adjList[curr];
            for (int j = 0; j < neighbors.size(); j++){
                int next = neighbors[j].first;
                int costFromCurrToNext = neighbors[j].second;
                int totalCost = costFromStartToCurr + costFromCurrToNext;
                if (dist[nhop+1][next] > totalCost){
                    dist[nhop+1][next] = totalCost;
                    pq.push(Node(next,totalCost,nhop+1));
                }
            }
        }
        int currMin = INF;
        for (int j = 0; j <= k; j++){
            if (dist[j][dst] < currMin){
                currMin = dist[j][dst];
            }
        }
        if (currMin == INF){return -1;}
        return currMin;
    }
    
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<ii>> adjList = getAdjList(n, flights);
        
        return dijkstra(n, src, dst, k+1, adjList);
    }
};