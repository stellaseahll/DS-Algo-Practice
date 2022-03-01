class Solution {
public:
    int min(int a, int b){
        if (a<b){return a;}
        return b;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        queue<int> q;
        int currSum = 0;
        int minLength = 1000000000;
        for (int j = 0; j < nums.size(); j++){
            int x = nums[j];
            q.push(x);
            currSum += x;
            if (currSum < target){continue;}
            while  ((currSum-q.front()) >= target){
                currSum -= q.front(); 
                q.pop();
            }
            minLength = min(minLength, q.size());
        }
        if (minLength == 1000000000){return 0;}
        return minLength;
    }
};