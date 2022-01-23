class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        bool noPositive = true;
        int max = -1000000000;
        for (int j = 0; j < nums.size(); j++){
            if (nums[j] >0){max = nums[j]; noPositive = false; break;}
            max = (nums[j] > max) ? nums[j] : max;
        }
        if (noPositive){return max;}
        int curr = nums[0];
        int res = max;
        for (int j = 1; j < nums.size(); j++){
            if (curr < 0){
                curr = 0;
            }
            if (nums[j] < 0){
                res = (curr > res) ? curr : res;
            }
            curr += nums[j];
        }
        return (curr > res) ? curr : res;
    }
};