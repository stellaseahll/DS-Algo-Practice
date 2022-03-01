class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n==1){return 1;}
        vector<int> curr = {nums[0],nums[1]};
        if (n == 2){
            if (curr[0] == curr[1]) {return 1;}
            return 2;
        }
        int j = 2;
        if (curr[0] == curr[1]){
            while (j < n && curr[0]==nums[j]){
                j++;
            }
            if (j == n){return 1;}
            curr[1] = nums[j];
        }
        // cout <<"j:" <<  j << endl;
        int count = 2;
        for (int k = j; k < n; k++){
            if (curr[0] > curr[1]){
                if (nums[k] <= curr[1]){
                    curr[1] = nums[k];
                }
                else {
                    // printf("(%d,%d)\n", curr[0],curr[1]);
                    curr[0] = curr[1];
                    curr[1] = nums[k];
                    count++;
                }
            }
            else{
                if (nums[k] >= curr[1]){
                    curr[1] = nums[k];
                }
                else{
                    // printf("(%d,%d)\n", curr[0],curr[1]);
                    curr[0] = curr[1];
                    curr[1] = nums[k];
                    count++;
                }
            }
        }
        return count;
        
    }
};