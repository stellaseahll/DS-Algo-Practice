class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> s;
        for (int j = 0; j < nums.size(); j++){
            if (s.count(nums[j])==1){
            
                if (abs(j- s[nums[j]]) <= k){return true;}
                s[nums[j]] = j;
            }
            else{
                s[nums[j]] = j;
            }
        }
        return false;        
    }
};