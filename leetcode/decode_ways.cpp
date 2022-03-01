class Solution {
public:
    bool isValid(string s){
        if (s[0]=='0'){return false;}
        if (s[0]=='1'){return true;}
        if (s[0]=='2'){
            if (s[1]>='0' && s[1]<='6'){return true;}
        }
        return false;
    }
    string trim(string s, int start, int end){
        return s.substr(start, end-start+1);
    }
    int decode(string s, vector<vector<int>>& memo, int start, int end){
        if (start>end){return 1;}
        if (memo[start][end]!=-1){return memo[start][end];}
        if (s[start]=='0'){
            return memo[start][end]=0;
        }
        if (start==end){
            return memo[start][end]=1;
        }
        
        if (isValid(trim(s,start,start+1))){
            return memo[start][end]=decode(s,memo,start+1,end)+decode(s,memo,start+2,end);   
        }
        return memo[start][end]=decode(s,memo,start+1,end);
    }
    int numDecodings(string s) {
        vector<vector<int>> memo(s.size(),vector<int>(s.size(),-1));
        return decode(s,memo,0,s.size()-1);
    }
};