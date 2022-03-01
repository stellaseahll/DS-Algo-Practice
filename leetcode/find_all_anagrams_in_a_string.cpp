class Solution {
public:
    bool isEqual(int *ht, int *ht2){
        for (int j = 0; j < 26; j++){
           if (ht[j] != ht2[j]){return false;}
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()){return {};}
        int ht[26];
        int ht2[26];
        vector<int> answer;
        int n = p.size();
        memset(ht,0,sizeof(ht));
        memset(ht2,0,sizeof(ht2));
        for (int j = 0; j < n; j++){
            ht[p[j]-'a']++;
            ht2[s[j]-'a']++;
        }
        if (isEqual(ht,ht2)){answer.push_back(0);}
        for (int j = 1; j < s.size()-n+1; j++){
            ht2[s[j-1]-'a']--;
            ht2[s[j+n-1]-'a']++;
            if (ht2[s[j+n-1]-'a'] != ht[s[j+n-1]-'a']){continue;}
            else{
                if (isEqual(ht,ht2)){answer.push_back(j);}
            }
        }
        return answer;
    }
};