class Solution {
public:
    string repeatString(string s, int n){
        if (s.find('[') == -1){
            string answer = "";
            for (int j = 0; j < n; j++){
                answer = answer + s;
            }
            return answer;
        }
        stack<int> intSt;
        stack<char> charSt;
        int j = 0; 
        string answer = "";
        while (j < s.size()){
            if (s[j] >= '0' && s[j] <= '9'){
                int count = 0;
                while (s[j] >= '0' && s[j] <= '9'){
                    count = count * 10 + (s[j] - '0');
                    j++;
                }
                j--;
                intSt.push(count);
            }
            else if (s[j] == ']'){
                string newStr = "";
                while (!charSt.empty() && charSt.top() != '['){
                    newStr = charSt.top()+newStr;
                    charSt.pop();
                }
                charSt.pop();
                int k = intSt.top();
                intSt.pop();
                newStr = repeatString(newStr,k);
                if (charSt.empty()){
                    answer = answer + newStr;
                }
                else{
                    for (int r = 0; r < newStr.size(); r++){
                        charSt.push(newStr[r]);
                    }
                }
                
            }
            else {
                charSt.push(s[j]);
            }
            j++;
        }
        string newStr = "";
        while (!charSt.empty()){
            newStr = charSt.top() + newStr;
            charSt.pop();
        }
        return answer+newStr;

    }
    string decodeString(string s) {

        return repeatString(s, 1);
    }
};