class Solution {
public:
    bool checkCycle(int start, const vector<vector<int>>& adjList, vector<bool>& isVisited, vector<int>& finishOrder, vector<bool>& recStack ){
        isVisited[start] = true;
        recStack[start] = true;
        vector<int> neighbors = adjList[start];
        for (int j = 0; j < neighbors.size(); j++){
            int neighbor = neighbors[j]; 
            if (!isVisited[neighbor]){
                bool hasCycle = checkCycle(neighbor, adjList, isVisited, finishOrder,recStack);
                if (hasCycle){
                    return true;
                }            
                recStack[neighbor] = false;
            }
            else if (recStack[neighbor]){
                return true;
            }
        }
        finishOrder.push_back(start);
        return false;
    }
    
    
    vector<vector<int>> getAdjList(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> adjList(numCourses,vector<int>{});
        for (int j = 0; j < prerequisites.size(); j++){
            int first = prerequisites[j][0];
            int second = prerequisites[j][1];
            adjList[second].push_back(first);
        }
        return adjList;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList = getAdjList(numCourses, prerequisites);
        vector<int> finishOrder;
        vector<bool> isVisited(numCourses,false);
        for (int j = 0; j < numCourses; j++){
            if (!isVisited[j]){
                vector<bool> recStack(numCourses,false);
                bool hasCycle = checkCycle(j, adjList, isVisited, finishOrder, recStack);
                if (hasCycle){return {};}
            }
        }
        for (int j = 0; j < numCourses/2; j++){
            int tmp = finishOrder[j];
            finishOrder[j] = finishOrder[numCourses-1-j];
            finishOrder[numCourses-1-j] = tmp;
        }
        return finishOrder;
    }
};