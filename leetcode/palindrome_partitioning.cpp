class Solution {
public:
    // bool isPalindrome(string s){
    //     for (int j = 0; j < s.size()/2; j++){
    //         if (s[j] != s[s.size()-1-j]){return false;}
    //     }
    //     return true;
    // }
    
    void partitionWord(string s, vector<string>& current, vector<vector<string>>& allPart, int idx, vector<vector<bool>>& memo){
        if (idx == s.size()){
            allPart.push_back(current);
            return;
        }
        for (int j = idx; j < memo[idx].size(); j++){
            if (memo[idx][j]){
                int len = j-idx+1;
                current.push_back(s.substr(idx,len));
                partitionWord(s, current, allPart, j+1, memo);
                current.pop_back();
            }
        }
        return;
    }

    vector<vector<string>> partition(string s) {
        int n = s.size(); 
        vector<vector<string>> ans(n,vector<string>{});
        vector<vector<bool>> memo(n,vector<bool>(n,false));
        for (int j = 0; j < n; j++){
            memo[j][j] = true;
        }
        for (int j = 0; j < n-1; j++){
            if (s[j] == s[j+1]){
                memo[j][j+1] = true;
            }
        }

        for (int j = 0; j < n-2; j++){
            int row = 0; 
            int col = 2+j;
            for (int k = 0; k < n-2-j; k++){
                if (memo[row+1][col-1]){
                    if (s[row] == s[col]){
                        memo[row][col] = true;
                    }
                }
                row++;
                col++;
            }
        }
        
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                cout << memo[j][k]<<" ";
               if (memo[j][k]){
                   int len = k-j+1;
                   // cout << s.substr(j,len) << endl;
               }
                
            }
            cout << endl;
        }
        vector<vector<string>> allPart;
        vector<string> current;
        partitionWord(s, current, allPart, 0, memo);
        return allPart;
    }
};