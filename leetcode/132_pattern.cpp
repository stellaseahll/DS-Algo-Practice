int INF = 1000000001;
typedef pair<int,int> ii;
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() <= 2) {return false;}
        stack<int> stk;
        int second = -INF;
        int n =  nums.size();
        for (int j = n-1; åj >= 0; j--){
            if (nums[j] < second){
                return true;
            }
            while (!stk.empty() && stk.top() < nums[j]){
                second = stk.top();
                stk.pop();
            }
            stk.push(nums[j]);
        }
        return false;
        
    }
};