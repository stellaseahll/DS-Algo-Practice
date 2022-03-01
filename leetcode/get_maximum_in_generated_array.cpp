class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0){return 0;}
        if (n <= 2){return 1;}
        vector<int> nums(n+1,0);
        nums[1] = 1;
        nums[2] = 1;
        int max = 1;
        for (int j = 3; j <= n; j++){
            if (j%2==0){
                nums[j] = nums[j/2]; 
            }
            else{
                nums[j] = nums[j/2] + nums[(j/2)+1];
            }
            if (nums[j] > max){max = nums[j];}
        }
        return max;
    }
};