#define INF 2000000000;
vector<vector<int>> neighbors = {{0,1},{0,-1},{1,0},{-1,0}};

struct Node{
    int x;
    int y;
    int costFromStart;
    Node(){};
    Node(int _x, int _y, int _cost){
        x = _x;
        y = _y;
        costFromStart = _cost;
    }
    bool operator() (const Node& lhs, const Node& rhs){
        return (lhs.costFromStart > rhs.costFromStart);
    }
};

class Solution {
    
public:
    int dijkstra(const vector<vector<int>>& grid){
        int M = grid.size(); 
        int N = grid[0].size();
        priority_queue<Node,vector<Node>,Node> pq;
        Node start(0,0,0); // always start from 0
        pq.push(start);
        int dist[M][N];
        for (int j = 0; j < M; j++){
            for (int k = 0; k < N; k++){
                dist[j][k] = INF;
            }
        }
        dist[0][0] = 0;
        while (!pq.empty()){
            Node curr = pq.top();
            pq.pop();
            if (dist[curr.x][curr.y] < curr.costFromStart){continue;}
            for (int j = 0; j < 4; j++){
                int x = curr.x + neighbors[j][0];
                int y = curr.y + neighbors[j][1];
                if (x < 0 || x >= M || y < 0 || y >= N){
                    continue;
                }
                int costFromCurr = 1;
                if (j == grid[curr.x][curr.y]-1){
                    costFromCurr = 0;
                }
                // printf("(%d,%d,%d)\n",x,y,costFromCurr);
                int totalCost = costFromCurr+curr.costFromStart;
                if (totalCost < dist[x][y]){
                    dist[x][y] = totalCost;
                    Node next(x,y,totalCost);
                    pq.push(next);
                }
                
            }
        }
        return dist[M-1][N-1];    
    }
    int minCost(vector<vector<int>>& grid) {
        return dijkstra(grid);
    }
};