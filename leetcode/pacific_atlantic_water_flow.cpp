vector<vector<int>> neighbors ={ {0,1}, {0,-1}, {1,0}, {-1,0}};
int INF = 1000000000;
typedef pair<int,int> ii;
class Solution {
public:
    vector<vector<bool>> bfs(vector<vector<int>>& heights, string s){
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> isVisited(m,vector<bool>(n,false));
        queue<ii> q;
        if (s == "atlantic"){
            for (int j = 0 ; j < n; j++){
                q.push(ii(m-1,j));
                isVisited[m-1][j] = true;
            }
            for (int j = 0; j < m; j++){
                q.push(ii(j,n-1));
                isVisited[j][n-1] = true;
            }
        }
        else if (s == "pacific"){
            for (int j = 0 ; j < n; j++){
                q.push(ii(0,j));
                isVisited[0][j] = true;
                
            }
            for (int j = 0; j < m; j++){
               q.push(ii(j,0));
            isVisited[j][0] = true;
            }
        }
        while (!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            int h = heights[row][col];
            q.pop();
            for (int k = 0; k < 4; k++){
                int i = row + neighbors[k][0];
                int j = col + neighbors[k][1];
                if (i < 0 || i >= m || j < 0 || j >= n){continue;}
                if (!isVisited[i][j] && heights[i][j] >= h){
                    isVisited[i][j] = true;
                    q.push(ii(i,j));
                }
            }
        }
        return isVisited;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
       vector<vector<bool>> atlantic =  bfs(heights, "atlantic");
      vector<vector<bool>> pacific =  bfs(heights, "pacific");
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> coordinates;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (atlantic[i][j] && pacific[i][j]){
                    coordinates.push_back({i,j});
                }
            }
        }
        return coordinates;
    }
};