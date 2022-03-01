typedef pair<int,int> ii;
vector<ii> neighbors = {ii(-1,0),ii(1,0),ii(0,1),ii(0,-1)};

class Solution {
public:
    void floodFill2(vector<vector<int>>& image, vector<vector<bool>>& isVisited,  int i, int j, int target, int newColor){
        if (i<0 || i >= image.size()) {return;}
        if (j<0 || j >= image[0].size()) {return;}
        if (isVisited[i][j]) {return;}
        isVisited[i][j] = true;
        if (image[i][j] != target){return;}
        image[i][j] = newColor;
        for (int k = 0; k < neighbors.size(); k++){
            int x = neighbors[k].first, y = neighbors[k].second;
            floodFill2(image, isVisited, i+x,j+y,target,newColor);
        }
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool>> isVisited(image.size(),vector<bool>(image[0].size(),false));
        floodFill2(image, isVisited, sr, sc, image[sr][sc], newColor);
        return image;
        
    }
};