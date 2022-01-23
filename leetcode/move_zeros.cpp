class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int j = 0; j < n; j++){
            if (nums[j] == 0){count++;}
        }
        int curr = 0;
        for (int j = 0; j < n; j++){
            if (nums[j] != 0){
                nums[curr++] = nums[j];
            }
        }
        for (int j = n-1; j >= n-count; j--){
            nums[j] = 0;
        }
    }
};