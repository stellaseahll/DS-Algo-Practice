class Solution {
public:
    int binarySearch(const vector<int>& nums, const int& target, int left, int right){
        if (left > right){return -1;}
        if (left == right){
            if (nums[left] == target){return left;}
            return -1;
        }
        if (right-left == 1){
            if (nums[left] == target){return left;}
            if (nums[right] == target){return right;}
            return -1;
        }
        int mid = (left + right)/2;
        if (nums[mid]==target){return mid;}
        if (nums[mid] > target){
            return binarySearch(nums, target, left, mid-1);
        }
        else{
            return binarySearch(nums, target, mid+1, right);
        }
    }
    int search(vector<int>& nums, int target) {
        return binarySearch(nums,target,0,nums.size()-1);
    }
};