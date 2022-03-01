typedef pair<int,int> ii;

class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        stack<vector<int>> s;
        s.push(intervals[0]);
        for (int j = 1; j < intervals.size(); j++){
            vector<int> curr = intervals[j];
            vector<int> prev = s.top();
            if (curr[0] > prev[1]) {
                s.push(curr);
                continue;
            }
            s.top()[1] = max(curr[1], prev[1]);
        }
        vector<vector<int>> answer;
        while (!s.empty()){
            answer.push_back(s.top());
            s.pop();
        }
        return answer;
    }
};