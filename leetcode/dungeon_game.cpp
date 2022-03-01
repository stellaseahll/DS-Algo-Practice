class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int M = dungeon.size();
        int N = dungeon[0].size();
        vector<vector<int>> memo(M,vector<int>(N,-1));
        memo[M-1][N-1] = max(1, 1-dungeon[M-1][N-1]);
        for (int j = N-2; j >= 0; j--){ // last row
            memo[M-1][j] = max(1, memo[M-1][j+1] - dungeon[M-1][j]);                       
        }
        for (int j = M-2; j >= 0; j--){ // last col
            memo[j][N-1] = max(1, memo[j+1][N-1] - dungeon[j][N-1]);                              
        }

        for (int j = M-2; j >= 0; j--){
            for (int k = N-2; k >= 0; k--){
                int rightHP = memo[j][k+1];
                int bottomHP = memo[j+1][k];
                int minHP = min(rightHP,bottomHP);
                memo[j][k] = max(1, minHP - dungeon[j][k]);
            }
        }
        return memo[0][0];
    }
};