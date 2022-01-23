class Solution {
public:
    string reversePrefix(string word, char ch) {
        int pos = -1;
        for (int j = 0; j < word.size(); j++){
            if (ch == word[j]){
                pos = j; 
                break;
            }
        }
        for (int j = 0; j < (pos+1)/2; j++){
            char tmp = word[j];
            word[j] = word[pos-j];
            word[pos-j] = tmp;
        }
        return word;
    }
};