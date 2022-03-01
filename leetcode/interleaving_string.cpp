class Solution {
    vector<vector<int>> memo;
public:
    int isIl(string s1, string s2, string s3, int idx1, int idx2, int idx3){
        if (memo[idx1][idx2] != -1){
            return memo[idx1][idx2];
        }
        int i = idx1;
        int j = idx2;
        if (idx3 == s3.size()){
            return memo[idx1][idx2] = true;
        }
        if (idx1 == s1.size()){
            if (s2.substr(idx2,s2.size()-idx2) == s3.substr(idx3,s3.size()-idx3)){return memo[idx1][idx2] = true;}
            return memo[idx1][idx2] = false;
        }
        if (idx2 == s2.size()){
            if (s1.substr(idx1,s1.size()-idx1) == s3.substr(idx3,s3.size()-idx3)){return memo[idx1][idx2] = true;}
            return memo[idx1][idx2] = false;
        }
        if (s1[idx1] != s3[idx3] && s2[idx2] != s3[idx3]){
            return memo[idx1][idx2] = 0;
        }
        if (s1[idx1] == s3[idx3]){
            memo[idx1+1][idx2] = isIl(s1,s2,s3,idx1+1,idx2,idx3+1);
        }
        if (s2[idx2] == s3[idx3]){
            memo[idx1][idx2+1] = isIl(s1,s2,s3,idx1,idx2+1,idx3+1);
        }
    
        if (memo[idx1+1][idx2] == 1 || memo[idx1][idx2+1] == 1){
            return memo[idx1][idx2] = 1;
        }
        else{
            return memo[idx1][idx2] = 0;
        } 
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if (s1 == "" && s2 == "" && s3 == ""){return true;}
        if (s1 == ""){
            return s2==s3;
        }
        if (s2 == ""){
            return s1==s3;
        }
        if (s1.size() + s2.size() != s3.size()){return false;}
        memo = vector<vector<int>>(s1.size()+1,vector<int>(s2.size()+1,-1));
        isIl(s1, s2, s3, 0, 0, 0);
        if (memo[0][0] == 1){return true;}
        return false;
    }
};