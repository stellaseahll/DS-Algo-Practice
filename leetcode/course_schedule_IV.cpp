class Solution {
public:
    vector<bool> bfs(int start, const vector<vector<int>>& adjList){
        queue<int> q;
        q.push(start);
        int nV = adjList.size();
        vector<bool> isVisited(nV,false);
        isVisited[start] = true;
        while (!q.empty()){
            int mod = q.front();
            q.pop();
            vector<int> nextMods = adjList[mod];
            for (int j = 0; j < nextMods.size(); j++){
                int nextmod = nextMods[j];
                if (!isVisited[nextmod]){
                    q.push(nextmod);
                    isVisited[nextmod] = true;
                }
            }
        }
        isVisited[start] = false;
        return isVisited;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adjList(numCourses,vector<int>{});
        for (int j = 0; j < prerequisites.size(); j++){
            int first = prerequisites[j][0];
            int second = prerequisites[j][1];
            adjList[first].push_back(second);
        }
        vector<vector<bool>> results(numCourses, vector<bool>{});
        vector<bool> ans;
        for (int j = 0; j < queries.size(); j++){
            int first = queries[j][0];
            int second = queries[j][1];
            if (results[first].size() == 0){
                results[first] = bfs(first, adjList);
            }
            ans.push_back(results[first][second]);
        }
        return ans;
        
    }
};