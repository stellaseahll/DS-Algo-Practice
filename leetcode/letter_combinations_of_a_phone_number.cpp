class Solution {
public:
    vector<string> s;
    Solution(){
        s = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    }
    void dfsLetter(string& digits, string curr, vector<string>& allString, int idx){
        if (idx == digits.size()){
            allString.push_back(curr);
            return;
        }
        string letters = s[digits[idx]-'2'];
        for (int j = 0; j < letters.size() ; j++ ){
            curr = curr + letters[j];
            dfsLetter(digits, curr, allString, idx+1);
            curr.erase(idx);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> allString;
        if (digits.size() == 0){return allString;}
        dfsLetter(digits, "", allString, 0);
        return allString;
    }
};