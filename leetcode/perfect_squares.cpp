vector<int> memo(10002,-1);
class Solution {
private:
    
public:
    Solution(){
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 2;
        memo[3] = 3;
    }
    int min(int a, int b){
        if (a<b){return a;}
        return b;
    }
    int findMin(int n){
        if (memo[n] != -1){return memo[n];}
        int currMin = 1000000000;
        int k = (int) sqrt(n);
        if (k*k == n){return memo[n]=1;}
        for (int j = 1; j <= k*k; j++){
            int curr = j*j;
            int diff = n-(curr);
            if (diff>0){
                memo[diff] = findMin(diff);
                currMin = min(currMin, 1+memo[diff]);
            }
        }
        return memo[n] = currMin;
    }
    
    int numSquares(int n) {
        return findMin(n);
    }
};