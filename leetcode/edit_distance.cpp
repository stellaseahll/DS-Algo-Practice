
class Solution {
public:
    int min(int a, int b, int c){
        if (a<b && a<c){return a;}
        if (b<c){return b;}
        return c;
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size(); 
        int memo[m+1][n+1];
        memset(memo, 0, sizeof(memo));
        for (int j = 0 ; j <= m; j++){
            memo[j][0] = j;
        }
        for (int k = 0 ; k <= n; k++){
            memo[0][k] = k;
        }
        for (int j = 1; j <= m; j++){
            for (int k = 1; k <= n; k++){
                if (word1[j-1] == word2[k-1]){
                    memo[j][k] = min(memo[j-1][k] + 1, memo[j][k-1]+1, memo[j-1][k-1]);
                }
                else{
                    memo[j][k] = min(memo[j-1][k] + 1, memo[j][k-1]+1, memo[j-1][k-1]+1);
                }
            }
        }
        return memo[m][n];
    }
};