typedef pair<int,int> ii;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<ii> pos; 
        int n = position.size();
        for (int j = 0; j < n; j++){
            pos.push_back(ii(position[j],j));
        }
        vector<double> time(n,0);
        sort(pos.begin(), pos.end());
        for (int j = 0; j < n; j++){
            int idx = pos[j].second;
            time[j] = (target-position[idx])*1.0 / speed[idx]; 
        }
        stack<double> stk;
        for (int j = n-1; j >= 0; j--){
            double currTime = time[j];
            if (stk.empty() || stk.top() < currTime){
                stk.push(currTime);
            }
        }
        return stk.size();
    }
};