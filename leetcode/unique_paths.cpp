class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m,vector<int>(n,0));
        for (int j = 0; j < m; j++){
            memo[j][0] = 1;
        }
        for (int j = 0; j < n; j++){
            memo[0][j] = 1;
        }
        for (int j = 1; j < m; j++){
            for (int k = 1; k < n; k++){
                memo[j][k] = memo[j][k-1] + memo[j-1][k];
            }
        }
        return memo[m-1][n-1];
    }
};