int INF = 2000000000;
typedef pair<int,int> ii;
class Solution {
public:

    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<ii> stk;
        int n = nums.size();
        vector<int> nge(2*n,-1);
        for (int j = 0; j < n ; j++){
            nums.push_back(nums[j]);
        }
        for (int j = 0; j < nums.size(); j++){
            int next = nums[j];
            while (!stk.empty() && stk.top().first < next){
                int elementIdx = stk.top().second; 
                nge[elementIdx] = nums[j];
                stk.pop();
            }
            stk.push(ii(next,j));
         }
        while (!stk.empty()){
            int elementIdx = stk.top().second; 
            stk.pop();
            nge[elementIdx] = -1;
        }
        vector<int> answer(nge.begin(),nge.begin()+n);
        return answer;
    }
};