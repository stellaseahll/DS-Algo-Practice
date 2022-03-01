typedef pair<int,bool> ib;
class Solution {
public:
    string getString(string s, int start, int end){
        return s.substr(start,end-start+1);
    }
    
    bool wordbreak(string s, const unordered_set<string>& dict, vector<vector<ib>>& memo, int start, int end){
        if (start > end) {return true;}
        if (memo[start][end].first != -1){
            return memo[start][end].second;
        }
        
        for (int j = start; j <= end; j++){
            string front = getString(s,start,j);
            if (dict.count(front) == 1){
                if (wordbreak(s,dict,memo,j+1,end)) {
                    memo[start][end].first = 1;
                    memo[start][end].second = true;
                    return memo[start][end].second;
                }   
            }
        }
        memo[start][end].first = 1;
        memo[start][end].second = false;
        return memo[start][end].second;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (int j = 0; j < wordDict.size(); j++){
            dict.insert(wordDict[j]);
        }
        int n = s.size();
        if (n == 0){
            return true;
        }
        vector<vector<ib>> memo(n,vector<ib>(n,ib(-1,false)));
        return wordbreak(s,dict,memo,0,n-1);
    }
};