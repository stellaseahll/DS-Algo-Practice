class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for (int j = 0; j < word.size(); j++){
            if (word[j]>='A' && word[j] <= 'Z'){count++;}
        }
        if (count == 0 || count == word.size()){return true;}
        if (count == 1 && (word[0]>='A' && word[0] <= 'Z') ){return true;}
        return false;
    }
};