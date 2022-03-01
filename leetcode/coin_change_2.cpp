class Solution {
public:
    int countWays(int amount, int type, const vector<int>& coins, vector<vector<int>>& memo){
        if (type >= coins.size()) {return 0;}
        if (amount == 0){return 1;}
        if (amount < 0){return 0;}
        if (memo[type][amount] != -1){return memo[type][amount]; }
        return memo[type][amount]  = countWays(amount, type+1 , coins, memo) + countWays(amount-coins[type], type, coins, memo);
    }
    
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(coins.size(), vector<int>(amount+1,-1));
        return countWays(amount, 0, coins, memo);
    }
};