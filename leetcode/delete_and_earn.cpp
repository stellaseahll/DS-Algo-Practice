class Solution {
public:
    int max(int a, int b){
        if (a>=b){return a;}
        return b;
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int> freq(10001,0);
        vector<int> memo(10001,0);
        for (int j = 0; j < nums.size(); j++){
            freq[nums[j]]++;
        }
        memo[0] = 0;
        memo[1] = freq[1];
        memo[2] = max(freq[1],freq[2]*2);
        for (int j = 3; j < freq.size(); j++){
            memo[j] = max(freq[j]*j + memo[j-2], memo[j-1]);
            
        }
        return memo[10000];
    }
};