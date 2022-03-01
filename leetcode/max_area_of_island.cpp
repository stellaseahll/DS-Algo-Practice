typedef pair<int,int> ii;
vector<vector<int>> neighbors = {{0,1},{0,-1},{1,0},{-1,0}};

class Solution {
public:
    int bfs(int i, int j, const vector<vector<int>>& grid, vector<vector<bool>>& isVisited){
        int m = grid.size();
        int n = grid[0].size();
        queue<ii> q;
        q.push(ii(i,j));
        isVisited[i][j] = true;
        int count = 1;
        while (!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++){
                int nextr = row + neighbors[k][0];
                int nextc = col + neighbors[k][1];
                if (nextr < 0 || nextr >= m || nextc < 0 || nextc >= n){continue;}
                if (!isVisited[nextr][nextc] && grid[nextr][nextc] == 1){
                    isVisited[nextr][nextc] = true;
                    count++;
                    q.push(ii(nextr,nextc));
                }
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxCount = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> isVisited(m,vector<bool>(n,false));
        for (int i = 0; i < m; i++){
             for (int j = 0; j < n; j++){
                 if (!isVisited[i][j] && grid[i][j] == 1){
                     int count = bfs(i,j,grid,isVisited);
                     maxCount = max(count, maxCount);
                 }
             }           
        }
        return maxCount;
    }
};