typedef pair<int,int> ii;
class Solution {
public:
    
    int max(int a, int b){
        if (a>b){return a;}
        return b;
    }
    int min(int a, int b){
        if (a<b){return a;}
        return b;
    }
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currMax = nums[0];
        if (n == 0){return 0;}
        if (n == 1){return nums[0];}
        vector<ii> memo(n,ii(0,0));
        if (nums[0]>0){
            memo[0] = ii(nums[0],0);
        }
        else{
            memo[0] = ii(0,nums[0]);
        }
        for (int j = 1; j < n; j++){
            if (nums[j]>0){
                memo[j] = ii(max(nums[j]*memo[j-1].first,nums[j]),nums[j]*memo[j-1].second); 
            }
            else if (nums[j]<0){
                memo[j] = ii(nums[j]*memo[j-1].second,min(nums[j]*memo[j-1].first,nums[j]));
            }
            else{
                memo[j] = ii(0,0);
            }
            if (memo[j].first == 0){
                currMax = max(memo[j].second,currMax);
            }
            else{
                currMax = max(memo[j].first,currMax);
            }
        }
        return currMax;
    }
};