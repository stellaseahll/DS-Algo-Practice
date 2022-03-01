class Solution {
public:
    void permute2(const vector<int>& nums, vector<vector<int>>& answer, vector<int>& curr, vector<bool>& isVisited){
        if (curr.size() == nums.size()){
            answer.push_back(curr);
            return;
        }
        for (int j = 0; j < nums.size(); j++){
            if (!isVisited[j]){
                curr.push_back(nums[j]);
                isVisited[j] = true;
                permute2(nums, answer, curr, isVisited);
                curr.pop_back();
                isVisited[j] = false;
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<bool> isVisited(nums.size(), false);
        vector<int> curr = {};
        permute2(nums, answer, curr, isVisited);
        return answer;
    }
};