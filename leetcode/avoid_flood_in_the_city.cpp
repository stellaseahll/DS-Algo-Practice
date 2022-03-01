class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n,1);
        unordered_map<int,int> hash;
        set<int> noRain;
        for (int j = n-1; j >= 0 ; j--){
            int lake = rains[j];
            if (lake>0){
                if (hash.count(lake)){ // if exist
                    int lastRain = hash[lake];
                    set<int>::iterator it = noRain.lower_bound(lastRain);
                    if (it == noRain.begin()){return vector<int>{};}
                    it--;
                    ans[*it] = lake;
                    hash[lake] = j;
                    noRain.erase(*it);
                    ans[j] = -1;
                }
                else{
                    hash[lake] = j;
                    ans[j] = -1;
                }
            }
            else{
                noRain.insert(j);
            }
        }
        return ans;
    }
};