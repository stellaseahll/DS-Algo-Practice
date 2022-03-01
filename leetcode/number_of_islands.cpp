typedef pair<int,int> ii;
vector<ii> neighbors = {ii(0,1), ii(1,0), ii(-1,0), ii(0,-1)};
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int j, int k, const int& M, const int& N){
        if (j < 0 || j >= M){return;}
        if (k < 0 || k >= N){return;}
        if (grid[j][k] != '1'){return;}
        grid[j][k] = '.';
        for (int i = 0; i < 4; i++){
            int x = j + neighbors[i].first;
            int y = k + neighbors[i].second;
            dfs(grid, x, y, M, N);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        int count = 0;
        for (int j = 0; j < M; j++){
            for (int k = 0; k < N; k++){
                if (grid[j][k] == '1'){
                    count++;
                    dfs(grid, j, k, M, N);
                }
            }
        }
        return count;
    }
};