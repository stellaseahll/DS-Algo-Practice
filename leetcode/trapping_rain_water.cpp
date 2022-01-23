typedef pair<int,int> ii;
class Solution {
public:
    ii getMax(vector<int>& height){
        int maxh = -1000;
        int idx = -1;
        for (int j = 0; j < height.size(); j ++){
            if (height[j] > maxh){ 
                maxh = height[j]; 
                idx = j;
            }
        }
        return ii(maxh,idx);
    }
    
    int trap(vector<int>& height) {
        ii p = getMax(height);
        int maxh = p.first;
        int maxi = p.second;
        int n = height.size();
        int ch = 0;
        int ca = 0;
        int maxa = 0;
        for (int j = 0; j <= maxi; j++){
            if (ch >= height[j]){
                ca += (ch-height[j]);
            }
            else{
                maxa += ca; 
                ch = height[j];
                ca = 0;
            }
        }
        ca = 0;
        ch = 0;
        for (int j = n-1; j >= maxi; j--){
            if (ch >= height[j]){
                ca += (ch-height[j]);
            }
            else{
                maxa += ca; 
                ch = height[j];
                ca = 0;
            }   
        }
        
        return maxa + ca;
    }
};