int INF = 1000000000;
vector<vector<int>> neighbors = {{0,1},{0,-1},{1,0},{-1,0}};
class Solution {
    int n;
public:
    void getMinMax(const vector<vector<int>>& grid, int& minVal, int& maxVal){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                minVal = min(minVal,grid[j][k]);
                maxVal = max(maxVal,grid[j][k]);
            }
        }
        return;
    }
    void dfs(const vector<vector<int>>& grid,int row, int col, vector<vector<bool>>& isVisited, int tolerance){
        for (int k = 0; k < 4; k++){
            int i = row + neighbors[k][0];
            int j = col + neighbors[k][1];
            if (i < 0 || i >= n || j < 0 || j >= n){continue;}
            if (!isVisited[i][j] && grid[i][j] <= tolerance){
                isVisited[i][j] = true;
                dfs(grid,i,j,isVisited,tolerance);
            }
        }
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int minVal = INF; 
        int maxVal = -1;
        getMinMax(grid,minVal,maxVal);
        minVal = grid[0][0];
        while (minVal < maxVal){
            vector<vector<bool>> isVisited(n,vector<bool>(n,false));
            isVisited[0][0] = true;
            int tolerance = (minVal+maxVal)/2;
            dfs(grid,0,0,isVisited,tolerance);
            if (isVisited[n-1][n-1]){
                maxVal = tolerance;                    
            }
            else{
                minVal = tolerance+1;
            }
        }
        return minVal;
    }
};