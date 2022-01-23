class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0){return 0;}
        sort(nums.begin(),nums.end());
        int currCount = 1, maxCount = 1;
        int curr = nums[0];
        for (int j = 1; j < nums.size(); j++){
            if (nums[j] == curr){
                continue;
            }
            if (nums[j]-curr == 1){
                currCount++;
            }
            else{
                currCount = 1;
            }
            curr = nums[j];
            if (currCount > maxCount){
                maxCount = currCount;
            }
        }
        return maxCount;
    }
};