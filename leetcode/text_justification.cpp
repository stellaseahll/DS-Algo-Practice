class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int numSentences = 0;
        int currWidth = 0;
        vector<int> stopIndex = {-1};
        vector<int> length = {-1};
        int j = 0;
        while (j < words.size()){
            if (currWidth == 0){
                numSentences++;
                currWidth += words[j].size();
                j++;
                continue;
            }
            if (currWidth + 1 + words[j].size() > maxWidth){
                stopIndex.push_back(j-1);
                length.push_back(currWidth);
                currWidth = 0;
                continue;
            }
            currWidth += 1 + words[j].size();
            j++;
        }
        stopIndex.push_back(words.size()-1);
        length.push_back(currWidth);
        vector<string> ans;
        for (int j = 1; j < stopIndex.size(); j++){
            int start = stopIndex[j-1]+1;
            int end = stopIndex[j];
            int numWords = end- start + 1;
            if (numWords == 1){
                string s = words[start];
                s = s + string(maxWidth-s.size(),' ');
                ans.push_back(s);
                continue;
            }
            int rem = (maxWidth - length[j])%(numWords-1);
            int numSpaces = 1 + (maxWidth - length[j])/(numWords-1);
            
            string s = "";
            if (j == stopIndex.size() - 1){
                for (int k = start; k <= end-1; k++){
                    s = s + words[k] + " ";
                }
                s = s + words[end];
                s = s + string(maxWidth-s.size(),' ');
                ans.push_back(s);
                continue;
            }
            for (int k = start; k <= end-1; k++){
                s = s + words[k];
                if (k - start < rem){
                    s = s + string(numSpaces+1,' ');
                }
                else{
                    s = s + string(numSpaces,' ');
                }
            }
            s = s + words[end];
            ans.push_back(s);
        }
        return ans;
    }
   
};