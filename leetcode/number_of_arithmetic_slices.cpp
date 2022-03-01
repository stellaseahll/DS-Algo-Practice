class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n<=2){return 0;}
        int count = 0;
        int memo[n];
        memset(memo,0,sizeof(memo));
        for (int j = 1; j < nums.size()-1; j++){
            if ((nums[j]-nums[j-1]) == (nums[j+1]-nums[j])){
                memo[j] = memo[j-1]+1;
            }
            count += memo[j];
        }
        return count;

    }
};