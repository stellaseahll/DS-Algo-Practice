class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size()<=1){return;}
        int n = nums.size()-k%nums.size();
        for (int j = 0; j < n ; j++){
            nums.push_back(nums[j]);
        }
        nums.erase(nums.begin(), nums.begin()+ n);
    }
};