typedef pair<int,int> ii;
class Solution {
public:
    void permute(const vector<int>& nums, unordered_map<int,int>& m, unordered_map<int,int>& currCount, vector<int>& curr, vector<vector<int>>& answer){
        int n = nums.size();
        if (curr.size() == n){
            answer.push_back(curr);
            return;
        }
        
        for (unordered_map<int,int>::iterator it=m.begin(); it != m.end(); it++){
            int currVal = it->first; 
            int totalCount = it->second; 
            int count = currCount[currVal];
            if (count < totalCount){
                currCount[currVal]++;
                curr.push_back(currVal);
                permute(nums, m, currCount, curr, answer);
                curr.pop_back();
                currCount[currVal]--;
            }
        }
        return ; 
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int> m; 
        unordered_map<int,int> currCount; 
        int n = nums.size();
        for (int j = 0; j < n; j++){
            currCount[nums[j]] = 0;
            if (m.count(nums[j])==0){
                m[nums[j]] = 1;
            }
            else{
                m[nums[j]]++;   
            }
        }
        vector<int> curr = {};
        vector<vector<int>> answer;
        permute(nums, m, currCount, curr, answer);
        return answer;
        
    }
};