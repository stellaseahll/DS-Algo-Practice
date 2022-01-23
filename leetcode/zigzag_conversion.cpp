class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {return s;}
        string answer = "";
        int diff = (numRows - 1)*2;
        for (int j = 0; j < numRows; j++){
            int idx = j;
            while (idx < s.size()){
                if (j == 0 || j == numRows-1){
                    answer = answer + s[idx];
                    idx += diff;
                    continue;
                }
                answer = answer + s[idx];
                if ((idx + diff - 2*j) < s.size()){
                    answer = answer + s[idx + diff - 2*j];
                }
                idx += diff;
            }
        }
        return answer;
    }
};