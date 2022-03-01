class Solution {
public:
    bool isAnagram(string s, string t) {
        int htS[26], htT[26];
        memset(htS,0,sizeof(htS));
        memset(htT,0,sizeof(htT));
        for (int j = 0; j < s.size(); j++){
            char c = s[j];
            htS[c-'a']++;
        }
        for (int j = 0; j < t.size(); j++){
            char c = t[j];
            htT[c-'a']++;
        }
        for (int j = 0; j < 26; j++){
            if (htT[j] != htS[j]){return false;}
        }
        return true;
    }
};