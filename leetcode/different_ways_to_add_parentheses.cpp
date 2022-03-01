class Solution {
public:
    void processExpression(string expression, vector<int>& nums, vector<char>& ops){
        int j = 0; 
        int n = expression.size();
        while (j < n){
            char c = expression[j];
            if (c >= '0' && c <= '9'){
                int count = 0;
                while (j < n && expression[j] >= '0' && expression[j] <= '9'){
                    count = count*10 + (expression[j] -'0');
                    j++;
    
                }
                j--;
                nums.push_back(count);
            }
            else{
                ops.push_back(c);
            }
            j++;
        }
    }
    
    int calculate(int a, int b, char op){
        if (op == '+'){
            return a+b;
        }
        if (op == '-'){
            return a-b;
        }
        if (op == '*'){
            return a*b;
        }
        return -1;
    }
    
    vector<int> compute(const vector<int>& nums, const vector<char>& ops, int start, int finish){
        vector<int> answer;

        if (start == finish){
            answer.push_back(nums[start]);
            return answer;
        }
        if (finish-start == 1){
            answer.push_back(calculate(nums[start],nums[finish],ops[start]));
            return answer;
        }
        
        for (int j = start; j < finish; j++){
            vector<int> L = compute(nums, ops, start, j);
            vector<int> R = compute(nums, ops, j+1, finish);
            for (int l = 0; l < L.size(); l++){
                for (int r = 0; r < R.size(); r++){
                    answer.push_back(calculate(L[l],R[r],ops[j]));
                }
            }
        }
        return answer;
    }
    
    vector<int> diffWaysToCompute(string expression) {
        vector<int> nums;
        vector<char> ops;
        processExpression(expression, nums, ops);
        vector<int> result = compute(nums, ops, 0, nums.size()-1);
        return result;
    }
};