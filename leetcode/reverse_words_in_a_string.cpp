class Solution {
public:
    string reverseWords(string s) {
        stringstream ss;
        ss << s;
        string tmp,ans = "";
        while (ss >> tmp){
            ans = " "+ tmp + ans; 
        }
        return ans.substr(1,ans.size()-1);
    }
};