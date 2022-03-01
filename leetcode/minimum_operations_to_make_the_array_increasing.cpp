class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        for (int j = 1; j < nums.size(); j++){
            if (nums[j] <= nums[j-1]){
                count += nums[j-1]+1-nums[j];
                nums[j] = nums[j-1]+1;
                
            }
        }
        return count;
    }
};