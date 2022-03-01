class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows == 0){return ans;}
        ans.push_back(vector<int>{1});
        if (numRows == 1){return ans;}
        ans.push_back(vector<int>{1,1});
        if (numRows == 2){return ans;}
        for (int j = 2; j < numRows; j++){
            vector<int> tmp(j+1,1);
            for (int k = 1; k<j;k++){
                tmp[k] = ans[j-1][k-1]+ans[j-1][k];
            }
            ans.push_back(tmp);
        }
        return ans;
        
    }
};