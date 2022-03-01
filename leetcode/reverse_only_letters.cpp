class Solution {
public:
    bool isLetter(char c){
        if (c>='a' && c<='z'){
            return true;
        }
        if (c>='A' && c<='Z'){
            return true;
        }
        return false;
    }
    string reverseOnlyLetters(string s) {
        deque<int> q;
        for (int j = 0; j < s.size(); j++){
            if (isLetter(s[j])){
                q.push_back(j);
            }
        }
        while (q.size()>1){
            char tmp = s[q.front()];
            s[q.front()] = s[q.back()];
            s[q.back()] = tmp;
            q.pop_front(); 
            q.pop_back();
        }
        return s;
    }
};
    