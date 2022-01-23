typedef pair<int,int> ii;
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int,int> ht;
        for (int j = 0; j < s.size(); j++){
            if (ht.count(s[j]) == 1) {
                ht[s[j]] = -1;
            }
            else{
                ht[s[j]] = j;
            }
        }
        int idx = 1000000000;
        for (unordered_map<int,int>::iterator it = ht.begin(); it != ht.end(); it++){
            if (it->second >=0 &&  it->second < idx) {
                idx = it->second;
            }
        }
        if (idx == 1000000000){return -1;}
        return idx;
    }
};