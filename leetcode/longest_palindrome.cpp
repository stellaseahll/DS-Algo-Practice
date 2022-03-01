class Solution {
public:
    int longestPalindrome(string s) {
        int ht[52];
        memset(ht,0,sizeof(ht));
        for (int j = 0; j < s.size(); j++){
            if (s[j] >= 'a' && s[j] <= 'z'){ht[s[j]-'a']++;}
            else {ht[s[j]-'A'+26]++;}
        }
        int count1 = 0;
        int count = 0;
        for (int j = 0; j < 52; j++){
            if (ht[j]%2==1){count1 = 1;}
            count += (ht[j]/2)*2;
        }
        return count +count1;
    }
};