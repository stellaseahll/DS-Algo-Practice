class Solution {
public:
    
    int numTrees(int n) {
        if (n==0){return 0;}
        if (n==1){return 1;}
        int memo[n+1];
        memset(memo, 0, sizeof(memo));
        memo[1] = 1;
        memo[0] = 1;
        for (int j = 2; j <= n ; j++){
            for (int k = 0; k <= j-1; k++){
                memo[j] += memo[k]*memo[j-1-k];
            }
        }
        return memo[n];
    }
};