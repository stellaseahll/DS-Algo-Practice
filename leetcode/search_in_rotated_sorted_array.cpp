class Solution {
public:
    int binarySearch(vector<int>& nums, int left, int right, int target){
        if (left == right){
            if (nums[left] != target){
                return -1;
            }
        }
        if (right - left == 1){
            if (nums[right] == target){return right;}
            if (nums[left] == target){return left;}
            return -1;
        }
        if (left > right){return -1;}
        int mid = (left + right)/2;
        int L = nums[left];
        int M = nums[mid];
        int R = nums[right];
        if (L == target){return left;}
        if (M == target){return mid;}
        if (R == target){return right;}
        if (target > L && target < M){
            return binarySearch(nums, left+1, mid-1, target);
        }
        if (target > M && target < R){
            return binarySearch(nums, mid+1, right-1, target);
        }
        if (M > L && M > R){
            return binarySearch(nums, mid+1, right-1, target);
        }
        if (M < R && M < L){
            return binarySearch(nums, left+1, mid-1, target);
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        return  binarySearch(nums, 0, nums.size()-1, target);
    }
};