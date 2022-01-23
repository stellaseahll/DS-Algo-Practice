class Solution {
public: //Start: 4:50PM
    bool canJump(vector<int>& nums) {
        vector<int> memo(nums.size(),0);
        for(int j = 0; j < nums.size(); j++){
            memo[j] = nums[j] + j;
        }
        int curr = memo[0];
        for (int j = 0; j < nums.size()-1; j++){
            if (memo[j] > curr){curr  = memo[j];}
            if (curr == j) {return false;}
        }
        return true;
    }
};