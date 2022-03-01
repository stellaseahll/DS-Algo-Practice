class Solution {
public:
    int balancedStringSplit(string s) {
        int l = 0, r = 0;
        int total = 0;
        for (int j = 0; j < s.size(); j++){
            if (s[j] == 'L'){l++;}
            else {r++;}
            if (r==l){
                total++;
                r = 0;
                l = 0;
                
            }
        }
        return total;
    }
};