class Solution {
    
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int memo[2][n];
        int maxLength = 0;
        memset(memo, 0, sizeof(memo));
        for (int j = 0; j < n; j++){
            if (nums1[0] == nums2[j]){
                memo[0][j] = 1;
                maxLength = 1;
            }
        }
        
        for (int i = 1; i < m; i++){
            int bi = i%2;
            for (int j = 0; j < n; j++){
                if (j == 0){
                    if (nums1[i] == nums2[j]){
                        memo[bi][j] = 1;
                        if (memo[bi][j]>maxLength){
                            maxLength = memo[bi][j];
                        }
                    }
                    else{
                        memo[bi][j] = 0;
                    }
                    continue;
                }
                if (nums1[i] == nums2[j]){
                    memo[bi][j] = memo[1-bi][j-1] + 1;
                    if (memo[bi][j]>maxLength){
                        maxLength = memo[bi][j];
                    }
                }
                else{
                    memo[bi][j] = 0;
                }
            }
        }
        return maxLength;
    }
};