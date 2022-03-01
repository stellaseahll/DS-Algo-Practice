class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> memo(m, vector<int>(n,0));
        for (int j = 0; j < m; j++){
            if (obstacleGrid[j][0] == 1){break;}
            memo[j][0] = 1;
        }
        for (int j = 0; j < n; j++){
            if (obstacleGrid[0][j] == 1){break;}
            memo[0][j] = 1;
        }
        for (int j = 1; j < m; j++){
            for (int k = 1; k < n; k++){
                if (obstacleGrid[j][k] == 1) {continue;}
                memo[j][k] = memo[j-1][k] + memo[j][k-1];
            }
        }
        return memo[m-1][n-1];
    }
};