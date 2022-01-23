class Solution {
public:
    int max(int a, int b){
        if (a>=b){return a;}
        return b;
    }
    int robSingle(vector<int>& nums){
        int n = nums.size();
        if (n==0){return 0;}
        if (n==1){return nums[0];}
        if (n==2){return max(nums[0],nums[1]);}
        vector<int> memo(n,0);
        memo[0] = nums[0];
        memo[1] = max(nums[0],nums[1]);
        for (int j = 2; j < n; j++){
            memo[j] = max(nums[j]+memo[j-2],memo[j-1]);
        }
        return memo[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==0){return 0;}
        if (n==1){return nums[0];}
        if (n==2){return max(nums[0],nums[1]);}
        if (n==3){return max(max(nums[0],nums[1]),nums[2]);}
        vector<int> v1(nums.begin(), nums.end()-1);
        vector<int> v2(nums.begin()+1, nums.end());
        return max(robSingle(v1),robSingle(v2));
        
    }
};