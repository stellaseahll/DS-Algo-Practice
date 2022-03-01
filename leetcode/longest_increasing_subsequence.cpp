class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n,-1);
        vector<int> index(n,-1);
        
        int currSize = 1;
        memo[0] = nums[0];
        index[0] = 0;

        
        for (int j = 1; j < n; j++){
            int val = nums[j];
            // returns greater than or equal
            int idx = lower_bound(memo.begin(), memo.begin()+currSize, val) - memo.begin();
            if (idx == -1 || idx == 0){
                memo[0] = val;
            }
            else{
                if (idx == currSize){
                    currSize++;
                }
                
                memo[idx] = val;
            }
        }
        return currSize;
    }
};