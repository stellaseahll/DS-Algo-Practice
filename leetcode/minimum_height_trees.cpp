
typedef pair<int,int> ii;
class Solution {
public:
    vector<vector<int>> getAdjList(int n, vector<vector<int>>& edges){
        vector<vector<int>> adjList(n,vector<int>{});
        for (int j = 0; j < edges.size(); j++){
            int v1 = edges[j][0];
            int v2 = edges[j][1];
            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1);
        }
        return adjList;
        
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList = getAdjList(n,edges);
        if (n == 1){return vector<int>{0};}
        vector<int> outDegree(n,0);
        queue<ii> q;
        vector<int> level(n,-1);
        vector<bool> isVisited(n,false);
        for (int j = 0; j < n; j++){
            outDegree[j] = adjList[j].size();
            if (outDegree[j] == 1){
                q.push(ii(j,0));
                level[j] = 0;
                isVisited[j] = true;
            }
        }
        int count = q.size();
        int maxLevel = 0;
        while (!q.empty()){
            int curr = q.front().first;
            int currLevel = q.front().second;
            q.pop();
            vector<int> neighbors = adjList[curr];
            for (int j = 0; j < neighbors.size(); j++){
                int neighbor = neighbors[j];
                if (isVisited[neighbor]){continue;}
                outDegree[neighbor]--;
                if (outDegree[neighbor] == 1){
                    q.push(ii(neighbor,currLevel+1));
                    isVisited[neighbor] = true;
                    level[neighbor] = currLevel+1;
                    if (level[neighbor] > maxLevel){maxLevel = level[neighbor];}
                    count++;
                }
            }
        }
        vector<int> answer;
        for (int j = 0; j < n; j++){
           if (level[j] == maxLevel){
               answer.push_back(j);
           }
        }
        return answer;
    }
};