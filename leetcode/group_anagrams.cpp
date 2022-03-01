class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for (int j = 0; j < strs.size(); j++){
            string s = strs[j];
            sort(s.begin(), s.end());
            m[s].push_back(strs[j]);
        }
        vector<vector<string>> ans;
        for (unordered_map<string,vector<string>>::iterator it = m.begin(); it != m.end(); it++ ){
            ans.push_back(it->second);
        }
        return ans;
    }
};