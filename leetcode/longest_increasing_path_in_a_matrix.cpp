class Solution {
public:
     int countWays(int i, int j, int M, int N, int prev, vector<vector<int>>& matrix, vector<vector<int>>& memo){
       if (i<0 || i >=M || j < 0 || j >= N || matrix[i][j] <= prev){return 0;}
         if (memo[i][j] != -1){return memo[i][j];}
        int d1 = countWays(i+1, j, M, N, matrix[i][j], matrix, memo);
        int d2 = countWays(i-1, j, M, N, matrix[i][j], matrix, memo);
        int d3 = countWays(i, j+1, M, N, matrix[i][j], matrix, memo);
        int d4 = countWays(i, j-1, M, N, matrix[i][j], matrix, memo);
         return memo[i][j] = max(max(d1+1,d2+1),max(d3+1,d4+1));
    }
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int M = matrix.size();
        int N = matrix[0].size(); 
        vector<vector<int>> memo(M, vector<int>(N,-1));
        int maxLength = 0;
        for (int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                countWays(i, j, M, N, -1, matrix,memo);
                maxLength = max(maxLength,memo[i][j]);
            }
        }
        
        return maxLength;
     
    }
};