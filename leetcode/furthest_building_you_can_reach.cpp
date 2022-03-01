class Solution {
public:
    bool canReach(const vector<int>& heights, int last, int bricks, int ladders){
        int numJumps = 0;
        long long numBricks = 0;
        priority_queue<int> pq;
        for (int j = 0; j < last; j++){
            int h1 = heights[j];
            int h2 = heights[j+1];
            if (h1 < h2){
                numJumps++;
                numBricks += h2-h1;
                pq.push(h2-h1);
            }        
        }
        if (numJumps <= ladders || numBricks <= bricks){ return true;}
        while (ladders--){
            numBricks -= pq.top();
            pq.pop();
        }
        return numBricks <= bricks;
    }
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int start = 0;
        int end = n-1;
        while (start < end){
            int mid = (start+end)/2;
            if (end-start == 1){
               if (canReach(heights,end,bricks,ladders)){
                   start = end;
               }
                else if (canReach(heights,start,bricks,ladders)){
                    end = start;
                }
            }
            else{
                if (canReach(heights,mid,bricks,ladders)){
                    start = mid;
                }
                else{
                    end = mid-1;
                }
            }
            
        }
        return start;
        
    }
};