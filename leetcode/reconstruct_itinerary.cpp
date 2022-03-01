
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,map<string,int>> edges;
        stack<string> answer;
        for (int j = 0; j < tickets.size(); j++){
            string start = tickets[j][0];
            string dest = tickets[j][1];
            if (edges[start].count(dest)==0){
                edges[start][dest] = 1;
            }
            else{
                edges[start][dest]++;
            }
            
        }
        stack<string> stk;
        stk.push("JFK");
        while (!stk.empty()){
            string curr = stk.top();
            if (edges[curr].size() == 0){
                answer.push(curr);
                stk.pop();
            }
            else{
                string next = edges[curr].begin()->first;
                if (edges[curr].begin()->second == 1){
                    edges[curr].erase(next);
                }
                else{
                    edges[curr].begin()->second--;
                }
                stk.push(next);
            }
        }
        vector<string> vs;
        while (!answer.empty()){
            vs.push_back(answer.top());
            answer.pop();
        }
        return vs;
        
    }
};