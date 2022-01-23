class Solution {
public: //Start: 3:35PM End: 3:54PM
    int min(int a, int b){
        if (a<=b){return a;}
        return b;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size()+1;
        if (n == 1) {return 0;}
        if (n == 2) {return cost[0];}
        if (n == 3) {return min(cost[0],cost[1]);}
        vector<int> memo(n,0);
        memo[0] = 0; 
        memo[1] = 0;
        for (int j = 2; j < n; j++){
            memo[j] = min(memo[j-1] + cost[j-1], memo[j-2] + cost[j-2]);
        }
        return memo[n-1];
    }
};