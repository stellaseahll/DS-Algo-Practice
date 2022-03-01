class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q;
        int n = deck.size();
        vector<int> sequence;
        vector<int> sorted = deck;
        vector<int> answer(n,0);
        sort(sorted.begin(),sorted.end());
        for (int j = 0; j < n ; j++){
            q.push(j);
        }
        while (!q.empty()){
            sequence.push_back(q.front());
            q.pop();
            if (!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        for (int j = 0 ; j < n; j++){
            answer[sequence[j]] = sorted[j];
        }
        return answer;
        
    }
};