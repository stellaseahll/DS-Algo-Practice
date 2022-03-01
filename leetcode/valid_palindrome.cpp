class Solution {
public:
    bool isLetter(char c){
        if (c>='a' && c<='z'){return true;}
        if (c>='A' && c<='Z'){return true;}
        if (c>='0' && c<='9'){return true;}
        return false;
    }
    char toLower(char c){
        if (c>='a' && c<='z'){return c;}
        if (c>='0' && c<='9'){return c;}
        return c-'A'+'a';
    }
    bool isPalindrome(string s) {
        if (s.size()<=1){return true;}
        int left = 0, right = s.size()-1;
        while (left<right){
            if (!isLetter(s[left])){
                left++;
                continue;
            }
            if (!isLetter(s[right])){
                right--;
                continue;
            }
            if (toLower(s[left++])!=toLower(s[right--])){return false;}
            
        }
        return true;
    }
};