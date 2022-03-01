class DisjointSet{
    private: 
    int size; 
    vector<int> s;
    vector<int> parent;
    
    public:
    DisjointSet(int _size){
        size = _size;
        s = vector<int>(size,-1);
        parent = vector<int>(size,-1);
    }
    int find(int v){
        if (s[v] < 0){return v;}
        return s[v] = find(s[v]);
    }
    void merge(int v1, int v2){
        v1 = find(v1);
        v2 = find(v2);
        if (v1 == v2){return;}
        if (s[v1] < s[v2]){ // v1 is parent;
            s[v2] = v1;
            return;
        }
        if (s[v1] == s[v2]){// v2 is parent
            s[v2]--;
        }
        s[v1] = v2;
        return;
    }
    vector<int> getParents(){
        for (int j = 0; j < size; j++){
            parent[j] = find(j);
        }
        return parent;
    }
};
vector<vector<int>> neighbors = {{0,1},{0,-1},{1,0},{-1,0}};
typedef pair<int,int> ii;
class Solution {
private:
    int m; 
    int n;
    int getElement(int i, int j){
        return i*n + j;
    }
public:
    void getIslands(const vector<vector<int>>& grid1, DisjointSet& ds){
        for (int j = 0; j < m; j++){
            for (int k = 0; k < n; k++){
                if (grid1[j][k] == 0){continue;}
                int v = getElement(j,k);
                for (int l = 0; l < 4; l++){
                    int nextRow = j + neighbors[l][0];
                    int nextCol = k + neighbors[l][1];
                    if (nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >= n){continue;}
                    if (grid1[nextRow][nextCol] == 0){continue;}
                    int nextV = getElement(nextRow,nextCol);
                    ds.merge(v,nextV);
                }
            }
        }
    }
    bool bfs(int row, int col, const vector<vector<int>>& grid2, const vector<int>& islands, vector<vector<bool>>& isVisited){
        isVisited[row][col] = true;
        int idx = getElement(row,col);
        int islandIdx = islands[idx];
        queue<ii> q;
        q.push(ii(row,col));
        bool isSubIsland = true;
        while (!q.empty()){
            ii curr = q.front();
            q.pop();
            for (int j = 0; j < 4; j++){
                int nextRow = curr.first + neighbors[j][0];
                int nextCol = curr.second + neighbors[j][1];
                if (nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >= n){continue;}
                if (grid2[nextRow][nextCol] == 0){continue;}
                if (isVisited[nextRow][nextCol]){continue;}
                isVisited[nextRow][nextCol] = true;
                int nextIdx = getElement(nextRow,nextCol);
                if (islands[nextIdx] != islandIdx){ 
                    isSubIsland = false;
                }
                q.push(ii(nextRow,nextCol));
            }
        }
        return isSubIsland;
        
    }
    int getSubIslands(const vector<vector<int>>& grid2, const vector<int>& islands){
        vector<vector<bool>> isVisited(m,vector<bool>(n,false));
        int count = 0;
        for (int j = 0; j < m; j++){
            for (int k = 0; k < n; k++){
                if (isVisited[j][k]){continue;}
                if (grid2[j][k] == 0){
                    isVisited[j][k] = true;
                    continue;
                }
                int v = getElement(j,k);
                bool isSubIsland;
                if (grid2[j][k] == 1 && islands[v] == -1){
                    isSubIsland = false;
                    bfs(j, k, grid2, islands, isVisited);
                }
                else{
                    isSubIsland = bfs(j, k, grid2, islands, isVisited);
                }
                if (isSubIsland){
                    count++;}
            }
        }
        return count;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();
        DisjointSet ds(m*n);
        getIslands(grid1,ds);
        vector<int> islands = ds.getParents();
        for (int j = 0; j < m; j++){
            for (int k = 0; k < n; k++){
                if (grid1[j][k] == 0){
                    int v = getElement(j,k);
                    islands[v] = -1;
                }
            }
        }
        return getSubIslands( grid2, islands);
    }
};