class Solution {
public:
    bool bfs(int start, vector<vector<int>>& adjList, vector<bool>& isVisited){
        isVisited[start] = true;
        vector<bool> checkCycle(adjList.size(),false);
        queue<int> q; 
        q.push(start);
        vector<int> parent(adjList.size(), -1);
        
        while (!q.empty()){
            int curr = q.front(); 
            q.pop();
            checkCycle[curr] = true;
            vector<int> nextMods = adjList[curr];
            for (int j = 0; j < nextMods.size(); j++){
                int nextmod = nextMods[j];
                int p = parent[curr];
                while (p != -1){
                    if (p == nextmod){
                        return false;
                    }
                    p = parent[p];
                }
                parent[nextmod] = curr;
                if (!isVisited[nextmod]){
                    q.push(nextmod);
                    isVisited[nextmod] = true;
                }
            }
        }
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses,vector<int>{});
        for (int j = 0; j < prerequisites.size(); j++){
            int first = prerequisites[j][0];
            int second = prerequisites[j][1];
            if (first == second) {return false;}
            adjList[first].push_back(second);
        }
        vector<bool> isVisited(numCourses, false);
        for (int j = 0; j < numCourses; j++){
            if (!isVisited[j]){
                bool isValid = bfs(j, adjList, isVisited);
                if (!isValid){return false;}
            }
        }
        return true;
    }
};