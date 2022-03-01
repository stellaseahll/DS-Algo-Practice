class Solution {
public:
    int max(int a, int b){
        if (a>b){return a;}
        return b;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> memo(n+1,1000000000);
        memo[0] = 0; 
        for (int j = 1; j <= n; j++){
            int width = books[j-1][0];
            int height = books[j-1][1];
            // start in new shelf
            memo[j] = height + memo[j-1];
            
            int currWidth = width;
            int currMaxHeight = height;
            for (int k = j-1; k > 0 ; k--){
                currWidth += books[k-1][0];
                if (currWidth > shelfWidth){
                    break;
                }
                currMaxHeight = max(currMaxHeight, books[k-1][1]);
                int totalHeight = currMaxHeight + memo[k-1];
                if ( totalHeight < memo[j]){
                    memo[j] = totalHeight;
                }
            }
        }
        return memo[n];
    }
};