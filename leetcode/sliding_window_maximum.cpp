typedef pair<int,int> ii;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<ii> q;
        vector<int> sliding;
        for (int j = 0; j < nums.size(); j++){
            while (!q.empty() && q.back().first<=nums[j]){
                q.pop_back();
            }
            q.push_back(ii(nums[j],j));
            if (j>=k-1){
                while (!q.empty() && j-q.front().second > k-1){
                    q.pop_front();
                }
                sliding.push_back(q.front().first);
            }
        }
        return sliding;
        
    }
};