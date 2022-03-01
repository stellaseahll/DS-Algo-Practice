class Solution {
public:
    vector<vector<int>> getAdjList(int n, const vector<vector<int>>& richer){
        vector<vector<int>> adjList(n,vector<int>{});
        for (int j = 0; j < richer.size(); j++){
            int rich = richer[j][0];
            int poor = richer[j][1];
            adjList[rich].push_back(poor);
        }
        return adjList;
    }
    
    vector<int> getInDegree(int n, const vector<vector<int>>& adjList){
        vector<int> inDegree(n,0);
        for (int j = 0; j < adjList.size(); j++){
            for (int k = 0; k < adjList[j].size(); k++){
                inDegree[adjList[j][k]]++;
            }
        }
        return inDegree;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adjList = getAdjList(n,richer);
        vector<int> inDegree = getInDegree(n,adjList);
        queue<int> q;
        vector<bool> isVisited(n,false);
        vector<int> mostQuiet(n,-1);
        for (int j = 0; j < n; j++){
            if (inDegree[j]==0){
                q.push(j);
                isVisited[j] = true;
            }
            mostQuiet[j] = j;
        }
        while (!q.empty()){
            int curr = q.front();
            q.pop();
            vector<int> neighbors = adjList[curr];
            for (int j = 0; j < neighbors.size(); j++){
                int neighbor = neighbors[j];
                inDegree[neighbor]--;    
                if (!isVisited[neighbor] && inDegree[neighbor] == 0){
                    isVisited[neighbor] = true;
                    q.push(neighbor);
                }
                if (quiet[mostQuiet[curr]] < quiet[mostQuiet[neighbor]]){
                    mostQuiet[neighbor] = mostQuiet[curr];
                }
            }
        }
        return mostQuiet;
        
    }
};