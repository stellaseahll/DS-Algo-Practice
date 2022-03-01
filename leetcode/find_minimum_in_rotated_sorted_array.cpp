class Solution {
public:
    int binarySearch(vector<int>& nums, int left, int right){
        if (left == right){
            return left;
        }
        if (left+1 == right){
            if (nums[left] > nums[right]){return right;}
            return left;
        }
        int mid = (left+right)/2;
        int L = nums[left];
        int M = nums[mid];
        int R = nums[right];
        if (L < M && L < R){return left;}
        if (L < M && R < M){
            return binarySearch(nums, mid+1, right);
        }
        return binarySearch(nums,left,mid);
    }
    int findMin(vector<int>& nums) {
        return nums[binarySearch(nums,0,nums.size()-1)];
    }
};