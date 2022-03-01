class Solution {
public:
    bool isMatch(string s, string p) {
        if (s == "" && p == ""){return true;}
        if (p == "" && s != ""){return false;}
        int m = p.size();
        int n = s.size();
        bool memo[m][n+1];
        memset(memo,false,sizeof(memo));
        if (p[0] == '*'){
            for (int k = 0; k <= n; k++){
                memo[0][k] = true;
            }
        }
        else{
            if (n == 0){return false;}
            if (s[0] == p[0] || p[0] == '?'){
                memo[0][1] = true;
            }
            else{
                return false;
            }
        }
        for (int j = 1; j < m; j++){
            // bool hasTrue = false;
            if (p[j] == '*'){
                int k = 0;
                while (k<=n && !memo[j-1][k]){
                    k++;
                }
                for (int r = k; r <= n; r++){
                    memo[j][r] = true;
                }
            }
            else{
                for (int k = 1; k <= n; k++){
                    if ((p[j] == s[k-1] || p[j] == '?') && memo[j-1][k-1]){
                        memo[j][k] = true;
                        // hasTrue = true;
                    }
                }
            }
            
            // if (!hasTrue){return false;}
        }
        
        // for (int j = 0; j < m; j++){
        //     for (int k = 0; k <= n; k++){
        //         cout << memo[j][k] << " ";
        //     }
        //     cout << endl;
        // }
        return memo[m-1][n];
        
    }
};