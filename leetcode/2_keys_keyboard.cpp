class Solution {
public:
    int minSteps(int n) {
        int memo[1001];
        memset(memo, 0, sizeof(memo));
        memo[0] = 0;
        memo[1] = 0;
        memo[2] = 2;
        memo[3] = 3;
        for (int j = 4; j <= n; j++){
            memo[j] = j;
            for (int k = j-1; k >=2; k--){
                if (j%k == 0){
                    memo[j] = min(memo[j], memo[k]+j/k);
                }
            }
        }
        return memo[n];
    }
};


