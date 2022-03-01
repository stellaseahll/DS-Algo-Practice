int INF = 1000000000;
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        bool ht[10001];
        memset(ht,false,sizeof(ht));
        int maxCount = -INF;
        int currCount = 0;
        queue<int> q;
        for (int j = 0; j < nums.size(); j++){
            int val = nums[j];
            if (!ht[val]){
                q.push(val);
                currCount += val;
                ht[val] = true;
            }
            else{
                while (q.front()!=val){
                    int front = q.front();
                    currCount -= front;
                    ht[front] = false;
                    q.pop();
                }
                q.pop();
                q.push(val);
            }
            
            maxCount = max(currCount,maxCount);
        }
        return maxCount;
    }
};