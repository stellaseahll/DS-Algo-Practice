class Solution {
public:
    bool bfs(int start, vector<vector<int>> adjList, vector<int>& colors){
        if (adjList[start].size() == 0){
            colors[start] = 2; 
            return true;
        }
        colors[start] = 1;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            int currCol = colors[curr];
            vector<int> neighbors = adjList[curr];
            for (int j = 0; j < neighbors.size(); j++){
                int neighbor = neighbors[j];
                if (colors[neighbor] == -1){
                    colors[neighbor] = 1-currCol;
                    q.push(neighbor);
                }
                if (colors[neighbor] == currCol){
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adjList(n,vector<int>{});
        for (int j = 0; j < dislikes.size(); j++){
            int v1 = dislikes[j][0]-1;
            int v2 = dislikes[j][1]-1;
            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1);
        }
        vector<int> colors(n,-1);
        for (int j = 0; j < n; j++){
            if (colors[j] == -1){
                bool check =  bfs(j, adjList, colors);
                if (!check){return false;}
            }
        }
        return true;
    }
};