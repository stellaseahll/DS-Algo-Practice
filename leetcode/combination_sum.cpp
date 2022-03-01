class Solution {
public:
    void combination(vector<int>& candidates, const int& target, int currVal, vector<vector<int>>& answers, vector<int>& curr, int idx){
        if (currVal > target){return;}
        if (currVal == target){
            answers.push_back(curr);
            return;
        }
        for (int j = idx; j < candidates.size(); j++){
            curr.push_back(candidates[j]);
            combination(candidates, target, currVal+candidates[j], answers, curr, j);
            curr.pop_back();
        }
        return;
    
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        combination(candidates, target, 0, ans, curr, 0);
        return ans;
    }
};