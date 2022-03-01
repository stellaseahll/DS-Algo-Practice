class Solution {
public:
    string smallestSubsequence(string s) {
        int ht[26];
        memset(ht,0,sizeof(ht));
        for (int j = 0; j < s.size(); j++){
            int idx = s[j]-'a';
            ht[idx] = j;
        }
        stack<char> stk;
        bool isUsed[26];
        memset(isUsed,false,sizeof(isUsed));
        for (int j = 0; j < s.size(); j++){
            char c = s[j];
            if (stk.empty() || (c > stk.top() && !isUsed[c-'a'])){
                stk.push(c);
                isUsed[c-'a'] = true;
                continue;
            }
            if (isUsed[c-'a']){continue;}
            while (!stk.empty() && c < stk.top() && !isUsed[c-'a']){
                if (ht[stk.top()-'a'] > j){
                    isUsed[stk.top()-'a'] = false;
                    stk.pop();
                }
                else{
                    break;
                }
            }
            stk.push(c);
            isUsed[c-'a'] = true;
        }
        string ans = "";
        while (!stk.empty()){
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};