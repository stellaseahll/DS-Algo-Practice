typedef pair<char,int> ci;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <11){return vector<string>{};}
        vector<string> vs;
        unordered_map<string,int> m;
        for (int j = 0; j <= s.size()-10; j++){
            string tmp = s.substr(j,10);
            if (m.count(tmp)==0){
                m[tmp]=1;
            }
            else{
                m[tmp]++;
            }
        }
        unordered_map<string,int>::iterator it;
        for (it = m.begin(); it != m.end(); it++){
            if (it->second>1){
                vs.push_back(it->first);
            }
        }
        
        
        return vs;
    }
};