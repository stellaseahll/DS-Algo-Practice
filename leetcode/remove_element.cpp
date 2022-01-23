class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0; 
        int n = nums.size();
        for (int j = 0; j < n; j++){
            if (nums[j] == val){count++;}
        }
        int idx = 0;
        for (int j = 0; j < n; j++){
            if (nums[j] != val){
                nums[idx] = nums[j];
                idx++;
            }
        }
        for (int j = 0; j < count; j++){
            nums[nums.size()-1-j]= val;
        }
        return n-count;
    }
};