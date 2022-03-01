class Solution {
public:
    int count(int j, vector<int>& nums, vector<bool>& isVisited, vector<int>& memo){
        if (memo[j] != -1){
            return memo[j];
        }
        if (isVisited[j]){return 0;}
        isVisited[j] = true;
        return memo[j] = 1+count(nums[j], nums, isVisited, memo);
    }
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int currMax = 0;
        vector<int> memo(n,-1);
        for (int j = 0; j < n; j++){
            if (memo[j] == -1){
                vector<bool> isVisited(n,false);
                count(j, nums, isVisited, memo);
            }
            currMax = max(memo[j], currMax);
        }
        return currMax;
    }
};