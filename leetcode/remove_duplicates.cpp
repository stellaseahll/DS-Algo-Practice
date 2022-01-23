class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0){return 0;}
        int curr = nums[0];
        int count = 1;
        for (int j = 1; j < nums.size(); j++){
            if (nums[j]!=curr){
                nums[count] = nums[j]; 
                curr = nums[j];
                count++;
            }
        }
        return count;
    }
};