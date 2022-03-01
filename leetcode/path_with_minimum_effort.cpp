vector<vector<int>> neighbors = {{0,1},{0,-1},{1,0},{-1,0}};
typedef pair<int,int> ii;
int INF = 1000000000;
// struct Node{
//     int v;
//     int costFromStart; 
//     Node(){};
//     Node(int _v, int _cost){
//         v = _v;
//         costFromStart = _cost;
//     };
//     bool operator()(const Node& lhs, const Node& rhs){
//         return lhs.costFromStart > rhs.costFromStart;
//     }
// }
class Solution {
    int numRow;
    int numCol;
public:
    void getDifference(const vector<vector<int>>& heights, int& minDiff, int& maxDiff){
        for (int i = 0; i < numRow; i++){
            for (int j = 0; j < numCol; j++){
                for (int k = 0; k < 4; k++){
                    int i2 = i + neighbors[k][0];
                    int j2 = j + neighbors[k][1];
                    if (i2 < 0 || i2 >= numRow || j2 < 0 || j2 >= numCol){
                        continue;
                    }
                    int diff = abs(heights[i][j] - heights[i2][j2]);
                    minDiff = min(minDiff,diff);
                    maxDiff = max(maxDiff,diff);
                }
            }
        }
    }
    void dfs(const vector<vector<int>>& heights,int row, int col, vector<vector<bool>>& isVisited, int tolerance){
        for (int k = 0; k < 4; k++){
            int i = row + neighbors[k][0];
            int j = col + neighbors[k][1];
            if (i < 0 || i >= numRow || j < 0 || j >= numCol){continue;}
            int diff = abs(heights[row][col] - heights[i][j]);
            if (!isVisited[i][j] && diff <= tolerance){
                isVisited[i][j] = true;
                dfs(heights,i,j,isVisited,tolerance);
            }
        }
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        numRow = heights.size();
        numCol = heights[0].size();
        if (numRow*numCol == 1){return 0;}
        int minDiff = INF, maxDiff = 0;
        getDifference(heights,minDiff,maxDiff);
        while (minDiff < maxDiff){
            vector<vector<bool>> isVisited(numRow,vector<bool>(numCol,false));
            isVisited[0][0]  = true;
            int tolerance = (minDiff + maxDiff)/2;
            dfs(heights,0,0,isVisited, tolerance);
            if (isVisited[numRow-1][numCol-1]){
                maxDiff = tolerance;
            }
            else{
                minDiff = tolerance+1;
            }
        }
        
        return minDiff;
        
    }
};