typedef pair<int,int> ii;
class Solution {
public:
    vector<vector<int>> getAdjList(int n, vector<vector<int>>& paths){
        vector<vector<int>> adjList(n,vector<int>{});
        for (int j = 0; j < paths.size(); j++){
            int v1 = paths[j][0]-1;
            int v2 = paths[j][1]-1;
            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1);
        }
        return adjList;
    }
    void bfs(int start, const vector<vector<int>>& adjList, vector<int>& color, vector<bool>& isVisited){
        queue<int> q;
        q.push(start);
        color[start] = 1;
        isVisited[start] = true;
        while (!q.empty()){
            int curr = q.front();
            int currColor = color[curr];
            int nextColor = (currColor + 1)%4;
            if (nextColor == 0){nextColor = 4;}
            q.pop();
            vector<int> neighbors = adjList[curr];
            for (int j = 0; j < neighbors.size(); j++){
                int next = neighbors[j];
                if (color[next] == currColor){
                    color[next] = nextColor; 
                }
                if (!isVisited[next]){
                    color[next] = nextColor;
                    isVisited[next] = true;
                    q.push(next);
                }
            }
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adjList = getAdjList(n,paths);
        vector<bool> isVisited(n,false);
        vector<int> color(n,-1);
        for (int j = 0; j < n; j++){
            if (!isVisited[j]){
                bfs(j, adjList, color, isVisited);
            }
        }
        return color;
    }
};