class Solution {
public: // START: 5:10PM STOP: 6:01PM
    int min(int a, int b){
        if (a<=b){return a;}
        return b;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n<=1){return 0;}
        vector<int> memo(n,0);
        pair<int,int> curr(1,min(nums[0],n-1));
        int jump = 1;
        while (curr.second < nums.size()-1){
            int reach = curr.second;
            for (int j = curr.first; j <= curr.second; j++){
                int x = nums[j] + j;
                if (x > reach){reach = x;}
            }
            curr.first = curr.second+1;
            curr.second = min(reach,n-1);
            jump++;
        }
        return jump;
    }
};