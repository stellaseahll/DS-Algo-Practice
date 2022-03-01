class Solution {
public:
    int maxProfit(vector<int>& prices){
        int minp = prices[0];
        int profit = 0;
        for (int j = 1; j < prices.size(); j++){
            if (prices[j] < minp){
                minp = prices[j];
            }
            else{
                profit = max(profit, prices[j]-minp);
            }
        }
        return profit;
    }
    // int maxProfit(vector<int>& prices) {
    //     int profit = 0; 
    //     int n = prices.size();
    //     int currMax = prices[n-1];
    //     for (int j = n-1; j >=0; j--){
    //         if (prices[j] > currMax){
    //             currMax = prices[j];
    //         }
    //         else{
    //             profit += currMax-prices[j];   
    //             cout << profit << endl;
    //         }
    //     }
    //     return profit;
    // }
};