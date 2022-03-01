class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> stk;
        string ans  = "";
        for (int j = 0; j < s.size(); j++){
            if (stk.empty() && s[j] != '('){
                ans = ans + s[j];
                continue;
            }
            if (s[j] != ')'){
                stk.push(s[j]);
            }
            else{
                queue<char> q;
                while (stk.top() != '('){
                    q.push(stk.top());
                    stk.pop();                   
                }
                stk.pop();
                if (stk.empty()){
                    while (!q.empty()){
                        ans = ans + q.front();
                        q.pop();
                    }
                }
                else{
                    while (!q.empty()){
                        stk.push(q.front());
                        q.pop();
                    }
                }
            }
        }
        return ans;
    }
};