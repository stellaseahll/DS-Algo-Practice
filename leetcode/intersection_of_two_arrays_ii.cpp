class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int ht[1001];
        vector<int> answer;
        memset(ht,0,sizeof(ht));
        for (int j = 0; j < nums1.size(); j++){
            int val = nums1[j];
            ht[val]++;
        }
        for (int j = 0; j < nums2.size(); j++){
            int val = nums2[j];
            if (ht[val] > 0){
                answer.push_back(val);
                ht[val]--;
            }
        }
        return answer;
    }
};