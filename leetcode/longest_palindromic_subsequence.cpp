class Solution {
public:
    int max(int a, int b){
        if (a>b){return a;}
        return b;
    }
    
    int longestPalindrome(const string& x, int i, int j, vector<vector<int>>& memo){
        if (memo[i][j]!=-1){return memo[i][j];}
        if (i==j){
            return memo[i][j] = 1;
        }
        if (x[i] == x[j]){
            if (j-i == 1){return memo[i][j] = 2;}
            return memo[i][j] = 2 + longestPalindrome(x,i+1,j-1,memo);
        }
        int s1 = longestPalindrome(x,i+1,j,memo);
        int s2 = longestPalindrome(x,i,j-1,memo);
        return memo[i][j] = max(s1, s2);
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> memo(s.size(),vector<int>(s.size(),-1));
        return longestPalindrome(s,0,s.size()-1,memo);
    }
};

