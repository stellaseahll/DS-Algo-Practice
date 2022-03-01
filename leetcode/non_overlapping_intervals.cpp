class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        stack<vector<int>> s;
        s.push(intervals[0]);
        int count = 0;
        for (int j = 1; j < intervals.size(); j++){
            vector<int> curr = intervals[j];
            vector<int> prev = s.top();
            if (curr[0] >= prev[1]) {
                s.push(curr);
                continue;
            }
            else{
                curr[1] = min(prev[1],curr[1]);
                count++;
                s.push(curr);
            }
            
        }
        return count;
    }
};