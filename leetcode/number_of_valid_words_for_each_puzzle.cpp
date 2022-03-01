class Solution {
public:
    int getNumWords(unordered_map<int,int>& m, string puzzle){
        int bitmask = getBitMask(puzzle);
        int submask = bitmask;
        int count = 0;
        int first = 1 << (puzzle[0]-'a');
        while (submask > 0){
            if (submask & first){
                if (m.count(submask) != 0){
                    count += m[submask];
                }
            }
            submask = (submask-1) & bitmask;
        }
        return count;
    }
    int getBitMask(string word){
        int bitmask = 0;
        for (int j = 0; j < word.size(); j++){
            int position = word[j]-'a';
            bitmask = (bitmask |  (1 << position));
        }
        return bitmask;  
    }
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int,int> m;
        for (int j = 0; j < words.size(); j++){
            int bm = getBitMask(words[j]);
            if (m.count(bm)==0){
                m[bm] = 1;
            }
            else{
                m[bm]++;
            }
        }
        vector<int> allCount;
        for (int j = 0; j < puzzles.size(); j++){
            allCount.push_back(getNumWords(m, puzzles[j]));
        }
        return allCount;
        
    }
};