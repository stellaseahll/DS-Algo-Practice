class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        if (n == 0){
            return ans;
        }
        ans[1] = 1;
        if (n == 1){
            return ans;
        }
        ans[2] = 1;
        if (n == 2){
            return ans;
        }
        int curr = 2;
        for (int j = 3; j <= n; j++){
            if (j == curr*2){
                curr = curr*2;
                ans[j] = 1;
            }
            else{
                ans[j] = ans[curr]+ans[j-curr];
            }
        }
        return ans;
    }
};