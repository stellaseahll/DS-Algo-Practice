class Solution {
public:
    int min(int a , int b){
        if (a<b){return a;}
        return b;
    }
    int coinChange(vector<int>& coins, int amount) {
        int INF = 1000000000;
        vector<int> memo(amount+1,INF);
        memo[0] = 0;
        for (int j = 1; j <= amount ; j++){
            for (int k = 0; k < coins.size(); k++){
                int val = j - coins[k];
                if (val < 0){continue;}
                memo[j] = min(memo[j],memo[val]+1);
            }       
        }
        if (memo[amount] == INF){return -1;}

        return memo[amount];
    }
};