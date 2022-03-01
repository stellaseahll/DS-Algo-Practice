typedef pair<int,int> ii;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n,0);
        int currMax = -30;
        int j = 1;
        stack<ii> stk;
        stk.push(ii(temperatures[0],0));
        for (int j = 1; j < n; j++){
            int currTemp = temperatures[j];
            while (!stk.empty()){
                int topTemp = stk.top().first;
                int topIdx = stk.top().second;
                if (topTemp >= currTemp){break;}
                answer[topIdx] = j-topIdx;
                stk.pop();
            }
            stk.push(ii(temperatures[j],j));
        }
        return answer;
        
        
    }
};