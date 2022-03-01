typedef pair<long long,long long> ll;
class Solution {
public:
    ll getHashKey(int x, int t){
        if (t==0){
            return ll(x,x);
        }
        ll ans; 
        if (x == 0){
            return ll(0,-1);   
        }
        long long k = (long long) x/t;
        if (x > 0){
            if (k*t == x){
                return ll(k-1,k);
            }
            return ll(k,k);
        }
        if (k*t == x){
            return ll(k-1,k);
        }
        return ll(k-1,k-1);
        
        return ll(k,k-1);
    }
    
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
       if (k==0){return false;}
        unordered_map<long long,long long> s;
        int n = nums.size();
        for (int j = 0; j < n; j++){
            
            ll key = getHashKey(nums[j], t);
            if (j > k){
                ll prevKey = getHashKey(nums[j-k-1], t);
                s.erase(prevKey.first);
                s.erase(prevKey.second);
            }
            if (s.count(key.first) == 1 || s.count(key.second) == 1){return true;}
            else if (s.count(key.first+1)) {
                if (abs(s[key.first+1] - nums[j]) <= t){return true;}
            }
            else if (s.count(key.first-1)) {
                if (abs(s[key.first-1] - nums[j]) <= t){return true;}
            }
            else if (s.count(key.second+1)) {
                if (abs(s[key.second+1] - nums[j]) <= t){return true;}
            }
            else if (s.count(key.second-1)) {
                if (abs(s[key.second-1] - nums[j]) <= t){return true;}
            }
            s[key.first] = nums[j];
            s[key.second] = nums[j];
        }
        return false;
    }
};