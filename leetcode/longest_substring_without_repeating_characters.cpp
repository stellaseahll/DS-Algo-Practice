typedef pair<char,int> ci;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        queue<char> q;
        int ft[300];
        memset(ft,0,sizeof(ft));
        int maxSize = 0;
        for (int j = 0; j < s.size(); j++){
            if (ft[s[j]] == 0){
                q.push(s[j]);
                ft[s[j]]++;
            }
            else{
                while (!q.empty() && q.front() != s[j]){
                    ft[q.front()]--;
                    q.pop();
                }
                q.pop();
                q.push(s[j]);
            }
            if (q.size() > maxSize) {
                maxSize = q.size();
            }
        }
        
        return maxSize;
    }
};