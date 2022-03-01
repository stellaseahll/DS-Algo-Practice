class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int idx = 0;
        for (int j = 0; j < pushed.size(); j++){
            if (stk.empty() || stk.top() != popped[idx]){
                stk.push(pushed[j]);
            }
            while (!stk.empty() && stk.top() == popped[idx]){
                stk.pop();
                idx++;
            }
        }
        return stk.empty();
    }
};