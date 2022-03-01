typedef pair<int,int> ii;
class Solution {
public:
    int findOneBall(int start, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        ii curr(0,start);
        for (int j = 0; j < m; j++){
            if (grid[curr.first][curr.second] == 1 && curr.second == n-1){
                return -1;
            }
            if (grid[curr.first][curr.second] == -1 && curr.second == 0){
                return -1;
            }
            if (grid[curr.first][curr.second] == 1 && grid[curr.first][curr.second+1] == -1){
                return -1;
            }  
            if (grid[curr.first][curr.second] == -1 && grid[curr.first][curr.second-1] == 1){
                return -1;
            }  
            curr = ii(curr.first + 1, curr.second + grid[curr.first][curr.second]);
        }
        return curr.second;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        int m = grid.size();
        int n = grid[0].size();
        for (int j = 0; j < n; j++){
            ans.push_back(findOneBall(j,grid));
        }
        return ans;
    }
};