class Solution {
public:
    bool checkSum(const vector<int>& nums, int mid, int m){
        int currSum = 0;
        int totalArr = 0;
        for (int j = 0; j < nums.size(); j++){
            if (totalArr == m-1){
                currSum += nums[j];
                continue;
            }
            if (currSum+nums[j] > mid){
                totalArr++;
                currSum = nums[j];
            }
            else{
                if (j == nums.size()-1){
                    totalArr++;
                }
                currSum += nums[j];
            }
        }
        return currSum <= mid;
    }
    int searchSum(const vector<int>& nums, int left, int right, int m){
        if (m==1){return right;}
        if (m== nums.size()){return left;}
        if (left == right){return left;}
        int mid = (left+right)/2;
        bool canSum = checkSum(nums,mid,m);
        if (canSum){
            return searchSum(nums,left,mid,m);            
        }
        return searchSum(nums,mid+1,right,m);
    }
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> cumSum(n+1,0);
        int minSum = -1;
        int maxSum = 0;
        for (int j = 0; j < n; j++){
            maxSum += nums[j];
            if (nums[j] > minSum ){minSum = nums[j];}
        }
        return searchSum(nums, minSum, maxSum, m);
        
    }
    
};