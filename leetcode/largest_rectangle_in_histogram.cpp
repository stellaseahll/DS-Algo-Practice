typedef pair<int,int> ii;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<ii> stk;
        stk.push(ii(0,-1));
        heights.push_back(0);
        int j = 0;
        while (j <= n){
            int h = heights[j];
            if ( stk.empty() || h >= stk.top().first ){
                stk.push(ii(h,j));
                j++;
            }
            else{
                ii tmp = stk.top();
                int H = tmp.first;
                stk.pop();
                int leftIdx;
                if (stk.empty()){
                    leftIdx = -1;
                }
                else{
                    leftIdx = stk.top().second;
                }                
                int rightIdx = j;
                maxArea = max(maxArea, H*(rightIdx-leftIdx-1));
            }
        }
        
        return maxArea;
    }
};