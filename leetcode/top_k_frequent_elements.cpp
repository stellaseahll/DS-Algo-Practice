typedef pair<int,int> ii;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for (int j = 0 ; j < nums.size(); j++){
            int curr = nums[j];
            if (m.count(curr) == 0){
                m[curr] = 1;
            }
            else{
                m[curr]++;
            }
        }
        priority_queue<ii> pq;
        for (map<int,int>::iterator it = m.begin(); it != m.end(); it++){
            int number = it->first;
            int freq = it->second;
            pq.push(ii(freq,number));
        }
        vector<int> answer;
        while (k--){
            answer.push_back(pq.top().second);
            pq.pop();
        }
        return answer;
    }
};