class Solution {
    long long pk[20001];
public:
    void getPk(int power, int k, int modulo){
        memset(pk,0,sizeof(pk));
        pk[0] = 1;
        for (int j = 1; j <= k; j++){
            pk[j] = (pk[j-1]* power)%modulo;
        }
    }
    string reverse(string s){
        
        for (int j = 0; j < s.size()/2; j++){
            char c = s[j];
            s[j] = s[s.size()-1-j];
            s[s.size()-1-j] = c;
        }
        return s;
    }
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        string ans;
        getPk(power, k, modulo);
        long long curr = 0;
        int n = s.size();
        string s2 = reverse(s);
        for (int j = 0; j < k; j++){
            int val = s2[j] - 'a' + 1;

            curr = ( (curr*power)%modulo  + val%modulo)%modulo;
        }
        
        if (curr == hashValue){ans = reverse(s2.substr(0,k));}
        for (int j = k; j < n; j++){
            int prev = s2[j-k] -'a' + 1;
            curr = (curr%modulo - (prev*pk[k-1])%modulo)%modulo;
            
            if (curr < 0){curr += modulo;}
            int val = s2[j] -'a'+1;
            curr = ( (curr*power)%modulo  + val%modulo)%modulo;
            if (curr == hashValue){
             ans  = reverse(s2.substr(j-k+1,k));
            }
        }
        return ans;
    }
};