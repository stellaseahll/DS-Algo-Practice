class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        map<int,int> m;
        vector<int> greaterIdx(n,0);
        vector<int> smallerIdx(n,0);
        for (int j = n-1; j >= 0; j--){
            int val = arr[j];
            map<int,int>::iterator it = m.lower_bound(val);
            if (it == m.end()){
                greaterIdx[j] = -1;
            }
            else{
                greaterIdx[j] = it->second;
            }
            if (it->first == val){
                smallerIdx[j] = it->second;
            }
            else{
                if (it == m.begin()){
                    smallerIdx[j] = -1;
                }
                else{
                    it--;
                    smallerIdx[j] = it->second;
                }
            }
        
            m[val] = j;
        }
        
        bool memo[2][n];
        memset(memo,false,sizeof(memo));
        memo[0][n-1] = true;
        memo[1][n-1] = true;
        int count = 1;
        for (int j = n-2; j >=0; j--){
            if (greaterIdx[j] != -1 && memo[1][greaterIdx[j]]){
                memo[0][j] = true;
            }
            if (smallerIdx[j] != -1 && memo[0][smallerIdx[j]]){
                memo[1][j] = true;
            }
            if (memo[0][j]){count++;}
        }
        return count;
    }
};