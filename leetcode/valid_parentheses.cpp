class Solution {
public:
    bool isMatch(char a, char b){
        if (a=='(' && b==')'){return true;}
        if (a=='[' && b==']'){return true;}
        if (a=='{' && b=='}'){return true;}
        return false;
    }
    bool isOpen(char a){
        if (a == '(' || a == '[' || a == '{'){return true;}
        return false;
    }
    
    bool isValid(string s) {
        if (s.size() == 0 || s.size()%2 ==1){return false;}
        stack<char> stk;
        for (int j = 0 ; j < s.size(); j++){
            if (isOpen(s[j])){
                stk.push(s[j]);
            }
            else{
                if (stk.empty() || !isMatch(stk.top(),s[j]) ){return false;}
                stk.pop();
            }
        }
        if (stk.empty()){return true;}
        return false;
    }
    
};