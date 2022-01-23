class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int j = 0; j < s.size()/2; j++){
            char tmp = s[j];
            s[j] = s[s.size()-1-j];
            s[s.size()-1-j] = tmp;
        }
        return;
    }
};