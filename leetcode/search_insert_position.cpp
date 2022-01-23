class Solution {
public:
    int min(int a, int b){
        return (a<b) ? a : b;
    }
    int lowerBound(const vector<int>& nums, int target, int left, int right){
        if (left>right){
            return -1;
        }
        if (left == right){
            if (nums[left] >= target){return left;}
            return left+1;
        }
        if (left == right-1){
            if (nums[left] >= target){return left;}
            if (nums[right] >= target){return right;}
            return right+1;
        }
        int mid = (left+right)/2;
        if (nums[mid]<target){
            return lowerBound(nums, target, mid+1, right);
        }
        return min(mid, lowerBound(nums, target, left, mid-1));
    }
    int searchInsert(vector<int>& nums, int target) {
        return lowerBound(nums, target, 0, nums.size()-1);
    }
};