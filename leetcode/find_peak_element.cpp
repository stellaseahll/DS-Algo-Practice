class Solution {
public:
    int getPeak(vector<int>& nums, int left, int right){
        if (right < left){
            return -1;
        }
        if (left == right){
            return left;
        }
        
        if (nums[left+1] < nums[left]){
            return left;
        }
        if (nums[right-1] < nums[right]){
            return right;
        }
        int mid = (right + left)/2;
        int L = nums[left+1];
        int R = nums[right-1];
        int M = nums[mid];
        int ML = nums[mid-1];
        int MR = nums[mid+1];
        if (M > ML && M > MR){return mid;}
        if (M < R){
            return getPeak(nums, mid+1, right-1);
        }
        if (M < L){
            return getPeak(nums, left+1, mid-1);
        }
        if( ML > M ){
            return getPeak(nums, left+1, mid-1);
        }
        if ( MR > M) {
            return getPeak(nums, mid + 1, right-1);
        }
        return -1;
    }
    
    int findPeakElement(vector<int>& nums) {
        return getPeak(nums, 0, nums.size()-1);
    }
};