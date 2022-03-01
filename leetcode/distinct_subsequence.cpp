class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size()){return 0;}
        if (s.size() == t.size()){
            if (s==t){return 1;}
            return 0;
        }
        int m = t.size();
        int n = s.size();  
        unsigned long long memo[m][n];
        memset(memo, 0, sizeof(memo));
        if (s[0] == t[0]) {memo[0][0] = 1;}
        for (int k = 1; k < n; k++){
            if (s[k] == t[0]){
                memo[0][k] = 1 + memo[0][k-1];
            }
            else{
                memo[0][k] = memo[0][k-1];
            }
        }
        for (int j = 1; j < m; j++){
            for (int k = j; k < n; k++){
                if (s[k] == t[j]){
                    memo[j][k] = memo[j-1][k-1] + memo[j][k-1];
                }
                else{
                    memo[j][k] = memo[j][k-1];
                }
            }
        }
        return memo[m-1][n-1];
    }
};