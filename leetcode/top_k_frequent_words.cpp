struct Word{
    int freq; 
    string word;
    Word(){};
    Word(int f, string s){
        freq = f;
        word = s;
    };
    bool operator<(const Word& y) const {
        if (freq == y.freq){
            return word < y.word;
        }
        return freq > y.freq;
    }
};

// struct WordCompare {
//     bool operator() (const Word& lhs, const Word& rhs){
//         if (lhs.freq == rhs.freq){
//             return lhs.word > rhs.word;
//         }
//         return lhs.freq < rhs.freq;
//     }
// };
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mString;
        set<Word> st;
        for (int j = 0; j < words.size(); j++){
            string s = words[j];
            if (mString.count(s) == 0){
                mString[s] = 1;
                st.insert(Word(mString[s],s));
            }
            else{
                st.erase(Word(mString[s],s));
                mString[s]++;
                st.insert(Word(mString[s],s));
            }
        }
        vector<string> ans;
        for (set<Word>::iterator it = st.begin(); it != st.end(); it++){
            if (ans.size() == k){break;}
            ans.push_back(it->word);
        }
        return ans;
    }
};