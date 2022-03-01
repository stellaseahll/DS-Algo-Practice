class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        map<int,int> m;
        for (int j = 0; j < nums.size(); j++){
            if (m.count(nums[j])==0){
                m[nums[j]] = 1;
            }
            else{
                m[nums[j]]++;
            }
        }
        vector<int> answer;
        for (map<int,int>::iterator it = m.begin(); it != m.end(); it++){
            vector<int> tmp(it->second,it->first);
            answer.insert(answer.end(), tmp.begin(), tmp.end());
        }
        return answer;
    }
};