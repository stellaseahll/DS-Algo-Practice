class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> isVisited(n,false);
        queue<int> q;
        q.push(0);
        isVisited[0] = true;
        while (!q.empty()){
            int curr = q.front();
            q.pop();
            vector<int> neighbors = rooms[curr];
            for (int j = 0; j < neighbors.size(); j++){
                int next = neighbors[j];
                if (!isVisited[next]){
                    q.push(next);
                    isVisited[next] = true;
                }
            }
        }
        for (int j = 0; j < n; j++){
            if (!isVisited[j]){return false;}
        }
        return true;
        
    }
};