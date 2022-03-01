class Solution {
public:
      int maxProfit(vector<int>& prices) {
        int profit = 0; 
        int n = prices.size();
        if (n<=1){return 0;}
        if (n==2){
            if (prices[0]<prices[1]){return prices[1]-prices[0];}
            return 0;
        }
        int currMax = prices[n-1];
        int currProfit = 0;
        for (int j = n-2; j >=0; j--){
            if (prices[j] > currMax){
                currMax = prices[j];
                profit += currProfit;
                currProfit = 0;
            }
            else{
                currProfit = max(currMax-prices[j],currProfit);
                if (j==0 || prices[j]>prices[j-1] && prices[j]>=prices[j+1]){
                    currMax = prices[j];
                    profit += currProfit;
                    currProfit = 0;
                }
            }
        }
        return profit;
    }
};