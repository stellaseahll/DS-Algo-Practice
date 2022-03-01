class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss;
        ss << s;
        string newStr;
        int x = 0;
        while (ss>>newStr){
            x = newStr.size();
        }
        return x;
    }
};