struct Pair{
    int first;
    int second;
    int sum;
    Pair(){};
    Pair(int a, int b){
        first = a;
        second = b;
        sum = a+b;
    }
    bool operator()(const Pair& lhs, const Pair& rhs){
        return lhs.sum > rhs.sum;
    }
};
class Solution {
public:
    int searchSum(vector<int>& nums1, vector<int>& nums2, int left, int right, int k){
        int m = nums1.size(), n = nums2.size();
        if (k==0){return left;}
        long long total = k;
        if (total >= (long long) m*n){return right;}
        if (left > right){return left;}
        int mid = (left+right)/2;
        int sum = 0;
        int prevIdx = nums2.size();
        for (int j = 0; j < m; j++){
            int val1 = nums1[j];
            int target = mid-val1;
            
            if (nums2[0]+val1 > mid){break;}
            prevIdx =  upper_bound(nums2.begin(),nums2.begin()+prevIdx,target) - nums2.begin();
            sum += upper_bound(nums2.begin(),nums2.begin()+prevIdx,target) - nums2.begin();
            if (sum > k){break;}
        }
        if (sum == k){return mid;}
        if (sum < k){
            return searchSum(nums1,nums2,mid+1,right,k);
        }
        return searchSum(nums1,nums2,left,mid-1,k);
        
    }
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        int minSum = nums1[0] + nums2[0];
        int maxSum = nums1[m-1] + nums2[n-1];
        int pairSum = searchSum(nums1, nums2, minSum, maxSum, k);
        priority_queue<Pair,vector<Pair>,Pair> pq;
        vector<vector<int>> ans;
        long long total = k;
        if (total > (long long) m*n) {total = m*n;}
        for (int j = 0; j < nums1.size(); j++){
            int curr = nums1[j];
            
            for (int i = 0; i < nums2.size(); i++){
                if (curr + nums2[i] > pairSum){break;}
                if (curr + nums2[i] == pairSum){
                    pq.push(Pair(curr,nums2[i]));
                }
                else{
                    ans.push_back(vector<int>{curr,nums2[i]});
                    total--;
                }
                
            }
        }
        
        while (total--){
            ans.push_back(vector<int>{pq.top().first, pq.top().second});
            pq.pop();
        }
        return ans;
    }
};