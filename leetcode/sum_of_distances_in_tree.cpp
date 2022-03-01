typedef pair<int,int> ii;
class Solution {
public:
    vector<int> bfsGetParent(int start, int n, const vector<vector<int>>& adjList){
        queue<int> q;
        vector<bool> isVisited(n,0);
        vector<int> parent(n,-1);
        isVisited[start] = true;
        q.push(start);
        while (!q.empty()){
            int curr = q.front();
            q.pop();
            vector<int> neighbors = adjList[curr];
            for (int j = 0; j < neighbors.size(); j++){
                int next = neighbors[j];
                if (!isVisited[next]){
                    isVisited[next] = true;
                    parent[next] = curr;
                    q.push(next);
                }
            }
        }
        return parent;
    }
    
    int getNumDescendants(int start, int currDist, int& dist, vector<int>& numNodes, vector<bool>& isVisited, const vector<vector<int>>& adjList, vector<vector<int>>& children){
        bool hasVisitors = false;
        vector<int> neighbors = adjList[start];
        for (int j = 0; j < neighbors.size(); j++){
            int next = neighbors[j];
            if (isVisited[next]){continue;}
            isVisited[next] = true;
            hasVisitors = true;
            dist += currDist + 1;
            numNodes[start] += getNumDescendants(next, currDist + 1, dist, numNodes, isVisited, adjList, children);
            children[start].push_back(next);
        }
        if (!hasVisitors){return numNodes[start] = 1;}
        return numNodes[start] = numNodes[start] + 1;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n,vector<int>{});
        vector<int> distance(n,0);
        vector<int> numNodes(n,0);
        for (int j = 0; j < edges.size(); j++){
            int x = edges[j][0];
            int y = edges[j][1];
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }
        vector<bool> isVisited(n,false);
        vector<vector<int>> children(n,vector<int>{});
        isVisited[0] = true;
        getNumDescendants(0, 0, distance[0], numNodes, isVisited, adjList, children);
        queue<int> q; 
        q.push(0);
        while (!q.empty()){
            int curr = q.front(); 
            int currDistance = distance[curr];
            q.pop(); 
            for (int j = 0; j < children[curr].size(); j++){
                int child = children[curr][j];
                distance[child] = distance[curr] + n - numNodes[child]*2;
                q.push(child);
            }
        }
        return distance;   
    }
};