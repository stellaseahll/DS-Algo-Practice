class Solution {
public: // Start : 3:56 PM
    int max(int a, int b){
        if (a>=b){return a;}
        return b;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==0){return 0;}
        if (n==1){return nums[0];}
        if (n==2){return max(nums[0],nums[1]);}
        vector<int> memo(n,0);
        memo[0] = nums[0];
        memo[1] = max(nums[0],nums[1]);  
        for (int j = 2; j < n; j++){
            memo[j] = max(memo[j-1],memo[j-2]+nums[j]);
        }
        return memo[n-1];
    }
};