class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int ht1[2000], ht2[2000];
        memset(ht1,0,sizeof(ht1));
        memset(ht2,0,sizeof(ht2));
        for (int j = 0; j < nums1.size(); j++){
            ht1[nums1[j]]++;
        }
        for (int j = 0; j < nums2.size(); j++){
            ht2[nums2[j]]++;
        }
        vector<int> ans;
        for (int j = 0; j <= 1000; j++){
            if (ht1[j] > 0 && ht2[j] > 0){
                ans.push_back(j);
            }
        }
        return ans;
    }
};