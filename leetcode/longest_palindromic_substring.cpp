class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLength = 1;
        int startIdx = 0;
        vector<vector<int>> memo(n,vector<int>(n,-1));
        for (int j = 0; j < n; j++){
            memo[j][j] = 1;
        }
        for (int j = 0; j < n-1 ; j++){
            if (s[j] == s[j+1]){
                memo[j][j+1] = 2;
                maxLength = 2;
                startIdx = j;
            }
        }
        
        
        for (int j = 3; j <= n; j++){
            for (int k = 0; k < n-j+1; k++){
                if (s[k] == s[k+j-1] && memo[k+1][k+j-2] != -1){
                    memo[k][k+j-1] = j;
                    if (memo[k][k+j-1] > maxLength){
                        maxLength = j;
                        startIdx = k;   
                    }
                }
            }
        }
        return s.substr(startIdx,maxLength);
    }
};