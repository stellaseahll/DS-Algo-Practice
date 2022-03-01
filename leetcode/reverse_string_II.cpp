class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0 ; i < n/(2*k)+1; i++){
            int start = 2*k*i;
            int end = (2*k*i+k);
            if (end >= n){end = n;}
            for (int j = start; j < (start+end)/2; j++){
                char tmp = s[j];
                s[j] = s[start+end-j-1];
                s[start+end-j-1] = tmp;
            }
        }
        return s;
    }
};