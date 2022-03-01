class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses,vector<int>{});
        vector<int> inDegree(numCourses,0);
        for (int j = 0; j < prerequisites.size(); j++){
            int firstMod = prerequisites[j][1];
            int secondMod = prerequisites[j][0];
            inDegree[secondMod]++;
            adjList[firstMod].push_back(secondMod);
        }
        queue<int> q;
        int count = 0;
        for (int j = 0; j < numCourses; j++){
            if (inDegree[j] == 0){
                q.push(j);
                count++;
            }
        }
        while (!q.empty()){
            int curr = q.front();
            q.pop();
            vector<int> nextMods = adjList[curr];
            for (int j = 0; j < nextMods.size(); j++){
                int next = nextMods[j];
                inDegree[next]--;
                if (inDegree[next] == 0){
                    q.push(next);
                    count++;
                }
            }
        }
        return (count == numCourses);
    }
};