int INF = 1000000000;
class Solution {
public:
    vector<vector<int>> getAdjMatrix(int n, vector<vector<int>>& edges){
        vector<vector<int>> adjMat(n, vector<int>(n,INF));
        for (int j = 0; j < n; j++){
            adjMat[j][j] = 0;
        }
        for (int j = 0; j < edges.size(); j++){
            int v1 = edges[j][0];
            int v2 = edges[j][1];
            int w = edges[j][2];
            adjMat[v1][v2] = w;
            adjMat[v2][v1] = w;
        }
        return adjMat;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>  adjMat = getAdjMatrix(n, edges);

        for (int k = 0; k < n; k++){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    adjMat[i][j] = min(adjMat[i][j], adjMat[i][k]+ adjMat[k][j]);
                }
            }
        }
        int city = -1;
        int count = INF;
        for (int j = 0; j < n; j++){
            int subcount = 0;
            for (int k = 0; k < n; k++){
                if (adjMat[j][k] <= distanceThreshold){
                    subcount++;
                }
            }
            if (subcount <= count){
                city = j;
                count = subcount;
            }
        }
        return city;
    
    }
};