class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        int cws = 0;
        for (int j = 0; j < n; j++){
            totalSum += nums[j];
            cws += j*nums[j];
        }
        int maxSum = cws;
        for (int j = n-1; j >= 0; j--){
            cws = cws + totalSum - n*nums[j];
            maxSum = max(cws, maxSum);
        }
        return maxSum;
        
        
        
    }
};