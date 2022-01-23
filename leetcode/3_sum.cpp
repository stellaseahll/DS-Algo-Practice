class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        if (nums.size() < 3) {return answer;}
        set<vector<int>> tmp;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if (nums[0]>0 || nums[n-1]<0){return answer;}
        if (nums[0]==0  && nums[n-1]==0){
            answer.push_back(vector<int>{0,0,0});
            return answer;
        }
        vector<int> nums2;
        map<int,int> m;
        for (int j = 0; j < n; j++){
            if (m.count(nums[j])==1){
                m[nums[j]]++;
            }
            else{
                m[nums[j]] = 1;
            }
        }
        for (map<int,int>::iterator it = m.begin(); it != m.end(); it++){
            if (it->second >= 1){
                nums2.push_back(it->first);
            }
            if (it->second >= 2){
                nums2.push_back(it->first);
            }
            if (it->second >= 3){
                nums2.push_back(it->first);
            }
        }
        n = nums2.size();
        for (int j = 0; j < n-2; j++){
            unordered_set<int> s;
            if (nums2[j] > 0){break;}
            int curr = -nums2[j];
            for (int k = j+1; k < n; k++){
                if (s.count(curr-nums2[k])==1){
                    tmp.insert(vector<int>{nums2[j],nums2[k],-nums2[j]-nums2[k]});
                }
                s.insert(nums2[k]);
            }
        }
        for (set<vector<int>>::iterator it = tmp.begin(); it != tmp.end(); it++){
            answer.push_back(*it);
        }
        return answer;
    }
};