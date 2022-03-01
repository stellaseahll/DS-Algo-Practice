class Solution {
public:
    int lowerBound(vector<int>& nums, int left, int right, int target){
        if (left > right){
            return left;
        }
        int mid = (left+right)/2;
        if (nums[mid] >= target){
           return lowerBound(nums,left,mid-1,target);
        }
        return lowerBound(nums,mid+1,right,target);
    }
    
    int upperBound(vector<int>& nums, int left, int right, int target){
        if (left > right){
            return left;
        }
        int mid = (left+right)/2;
        if (nums[mid] <= target){
           return upperBound(nums,mid+1,right,target);
        }
        return upperBound(nums,left,mid-1,target);
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int iUp = upperBound(nums, 0, nums.size()-1, target);
        int iLow = lowerBound(nums, 0, nums.size()-1, target);    
        if (iLow == nums.size() || nums[iLow] != target){
            return vector<int>{-1,-1};
        }
        return vector<int>{iLow,iUp-1};
    }
};