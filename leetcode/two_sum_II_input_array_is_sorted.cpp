class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> m;
        int n = numbers.size();
        for (int j = 0; j < n; j++){
            m[numbers[j]] = j;
        }
        for (int j = 0; j < n-1; j++){
            if (m.count(target-numbers[j])==1){
                return vector<int>{j+1,m[target-numbers[j]]+1};
            }
        }
        return vector<int>{-1,-1};
    }
};