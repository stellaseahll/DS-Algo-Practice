class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 1){
            return vector<int>{0,1};
        }
       vector<int> prev = grayCode(n-1);
        int N = prev.size();
        for (int j = N-1; j >=0; j--){
            int val = prev[j];
            prev.push_back(val + pow(2,n-1));
        }
        return prev;
    }
};