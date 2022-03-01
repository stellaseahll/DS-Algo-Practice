class Solution {
    map<string,bool> m;
public:
    bool isScramble(string s1, string s2) {
        if (s1==s2){
            return true;
        }
        if (s1.size() != s2.size()){
            return false;
        }
        if (s1.size()<=1){return false;}
        if (m.count(s1 + "+" + s2) == 1){
            return m[s1 + "+" + s2];
        }
        if (m.count(s2 + "+" + s1) == 1){
            return m[s2 + "+" + s1];
        }
        bool isValid = false;
        int n = s1.size();
        for (int j = 1; j <= n-1; j++){
            if (isScramble(s1.substr(0,j),s2.substr(0,j)) &&
               isScramble(s1.substr(j,n-j),s2.substr(j,n-j))
               ){
                
                isValid = true;
                break;
            }
            else if  (isScramble(s1.substr(0,j),s2.substr(n-j,j)) &&
               isScramble(s1.substr(j,n-j),s2.substr(0,n-j))
               ){
                isValid = true;
                break;
            }
        }
        m[s1 + "+" + s2] = isValid;
        m[s2 + "+" + s1] = isValid;
        return isValid;
    }
};