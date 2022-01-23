class Solution {
public:
    int min(int a, int b){
        if (a<b) {
            return a;
        }
        return b;
    }

    int upperBound(vector<int>& arr, int left, int right, int target){
        if (left == right){
            if (target <= arr[left]){return left;}
            return left+1;
        }
        if (right-left == 1){
            if (target <= arr[left]){return left;}
            if (target <= arr[right]){return right;}
            return right+1;
        }
        int mid = (left+right)/2;
        if (target <= arr[mid]){
            return min(mid,upperBound(arr,left,mid-1,target));
        }
        else{
            return upperBound(arr,mid+1,right,target);
        }
        return -1;
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> vii;
        for (int j = 0; j < nums.size(); j++){
            vii.push_back(pair<int,int>(nums[j],j));
        }
        sort(vii.begin(), vii.end());
        vector<int> sorted;
        for (int j = 0; j < nums.size(); j++){
            sorted.push_back(vii[j].first);
        }
        for (int j = 0; j < sorted.size(); j++){
            int idx = upperBound(sorted, j+1, sorted.size()-1, target - sorted[j]);
            if (idx > j && idx < sorted.size() && (sorted[j] + sorted[idx] == target)){
                vector<int> v = {vii[j].second,vii[idx].second};
                return v;
            }
            if ((idx == j) && (sorted[j] + sorted[j+1] == target)){
                vector<int> v = {vii[j].second,vii[j+1].second};
                return v;
            }
        }
        vector<int> v = {-1,-1};
        return v;
    }
};