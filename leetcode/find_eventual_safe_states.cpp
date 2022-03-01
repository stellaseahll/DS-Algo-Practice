class Solution {
public:
    vector<int> getInDegree(int n, vector<vector<int>>& adjList){
        vector<int> inDegree(n,0);
        for (int j = 0; j < n; j++){
            for (int k = 0; k < adjList[j].size(); k++){
                int v = adjList[j][k];
                inDegree[v]++;
            }
        }
        return inDegree;
        
    }
    vector<vector<int>> reverse(int n, vector<vector<int>>& graph){
        vector<vector<int>> adjList(n,vector<int>{});
        for (int j = 0; j < n; j++){
            for (int k = 0; k < graph[j].size(); k++){
                int v = graph[j][k];
                adjList[v].push_back(j);
            }
        }
        return adjList;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph = reverse(n,graph);
        vector<int> inDegree = getInDegree(n,reverseGraph);
        queue<int> q;
        vector<bool> isSafe(n,false);
        for (int j = 0; j < n; j++){
            if (inDegree[j] == 0){
                q.push(j);
                isSafe[j] = true;
            }
        }
        while (!q.empty()){
            int curr = q.front();
            q.pop();
            vector<int> neighbors = reverseGraph[curr];
            for (int j = 0; j < neighbors.size(); j++){
                int neighbor = neighbors[j];
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0){
                    q.push(neighbor);
                    isSafe[neighbor] = true;
                }
            }
        }
        vector<int> answer;
        for (int j = 0; j < n; j++){
            if (isSafe[j]){
                answer.push_back(j);
            }
        }
        return answer;
    }
};