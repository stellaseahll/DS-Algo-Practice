typedef pair<int,int> ii;
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        vector<ii> memo(n,ii(0,0));
        if (nums[0] > 0){
            memo[0].first = 1; // number of positive
        }
        else if (nums[0] < 0){
            memo[0].second = 1; // number of negative
        }
        int len = memo[0].first; 
        for (int j = 1; j < n; j++){
            if (nums[j] < 0){
                if (memo[j-1].second == 0){
                    memo[j].first = 0;
                }
                else{
                    memo[j].first = memo[j-1].second + 1;
                }
                memo[j].second = memo[j-1].first + 1;
            }
            if (nums[j] >0){
                memo[j].first = memo[j-1].first + 1;
                if (memo[j-1].second == 0) {
                    memo[j].second = 0;
                }
                else{
                    memo[j].second = memo[j-1].second + 1;
                }
            }
            if (nums[j] == 0){
                memo[j].first = 0;
                memo[j].second = 0;
            }
            if (memo[j].first > len){
                len = memo[j].first;
            }
        }
        return len;
    }
};