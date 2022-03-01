class Solution {
public:
    bool isLower(char c){
        if (c >= 'a' && c <= 'z'){return true;}
        return false;
    }
    
    bool isUpper(char c){
        if (c >= 'A' && c <= 'Z'){return true;}
        return false;
    }
    
    bool isMatch(string s, string pattern){
        if (pattern.size() > s.size()){return false;}
        int i = 0, j = 0;
        while (j < pattern.size() && i < s.size()){
            if (isLower(s[i]) && isUpper(pattern[j])){
                i++;
            }
            else if (isLower(s[i]) && isLower(pattern[j])){
                if (s[i] != pattern[j]){i++;}
                else{
                    i++;
                    j++;
                }
            }
            else if (isUpper(s[i]) && isUpper(pattern[j])){
                if (s[i] != pattern[j]){return false;}
                i++;
                j++;
            }
            else{
                return false;
            }
            
        }
        if (j != pattern.size()){return false;}
        if (j == pattern.size()){
            while (i < s.size()){
                if (isUpper(s[i])){return false;}
                i++;
            }
        }
        return true;
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> answer;
        for (int j = 0; j < queries.size(); j++){
            answer.push_back(isMatch(queries[j],pattern));
        }
        return answer;
    }
};