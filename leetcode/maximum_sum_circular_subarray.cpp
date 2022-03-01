class Solution {
public:
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int currSum = 0;
        int currIdx = 0; 
        int maxSum = -1000000000;
        int n = nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end());
        while (currIdx < n){
            currSum = 0;
            bool isBroken = false;
            bool isAllPositive = true;
            for (int j = currIdx; j < n + currIdx; j++){
                currSum += nums[j];
                if (nums[j]<0){
                    isAllPositive = false;
                }
                if (currSum > maxSum){
                    maxSum = currSum;
                }
                if (currSum < 0){
                    currIdx = j+1;
                    isBroken = true;
                    break;
                }
            }
            if (isAllPositive){break;}
            if (!isBroken){currIdx++;}
        }
        
        return maxSum;
    }
};