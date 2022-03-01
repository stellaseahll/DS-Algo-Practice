class Solution {
public:
    bool isPartiallyBipartite(int start, vector<vector<int>>& graph, vector<int>& color){
        color[start] = 0;
        queue<int> q;
        q.push(start);
        while (!q.empty()){
            int curr = q.front();
            int currColor = color[curr];
            q.pop();
            vector<int> neighbors = graph[curr];
            for (int j = 0; j < neighbors.size(); j++){
                int next = neighbors[j];
                if (color[next]==-1){
                    color[next]= 1-currColor;
                    q.push(next);
                }
                else if (color[next] == currColor){
                    return false;
                }
            }
        }
        return true;
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for (int j = 0; j < n; j++){
            if (color[j] != -1){continue;}
            if (!isPartiallyBipartite(j,graph,color)){
                return false;
            }
        }
        return true;
        
    }
};