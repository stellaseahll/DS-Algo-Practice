typedef pair<int,int> ii;
vector<ii> pairs({ii(0,1),ii(0,-1),ii(-1,0),ii(1,0)});

class Solution {
public:
    void dfs(int i, int j, const int& M, const int& N, const vector<vector<int>>& grid, int& paths, int steps, const int& totalSteps, vector<vector<bool>>& isVisited){
        if (i < 0 || i >= M){return;}
        if (j < 0 || j >= N){return;}
        if (grid[i][j] == -1){return;}
        if (grid[i][j] == 2){
            if (steps == totalSteps){paths++;}
            return;
        }
        for (int k = 0; k < 4; k++){
            int x = pairs[k].first, y = pairs[k].second;
            if (i+x < 0 || i+x >= M) {continue;}
            if (j+y < 0 || j+y >= N) {continue;}
            if (!isVisited[i+x][j+y]){
                isVisited[i+x][j+y] = true;
                dfs(i+x, j+y, M, N, grid, paths, steps+1, totalSteps, isVisited);
                isVisited[i+x][j+y] = false;
            }
        }
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startRow, startCol;
        int totalSteps = 0; 
        int M = grid.size(), N = grid[0].size();
        for (int j = 0; j < M; j++){
            for (int k = 0; k < N; k++){
                if (grid[j][k] == 1){
                    startRow = j;
                    startCol = k;
                }
                if (grid[j][k] != -1){
                    totalSteps++;
                }
            }
        }
        vector<vector<bool>> isVisited(M,vector<bool>(N,false));
        isVisited[startRow][startCol] = true;
        int paths = 0;
        dfs(startRow, startCol, M, N, grid, paths, 1, totalSteps, isVisited);
        return paths;
        
    }
};