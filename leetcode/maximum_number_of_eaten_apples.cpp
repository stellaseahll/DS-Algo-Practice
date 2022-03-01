struct Apple{
    int d;
    int n;
    Apple(){};
    Apple(int _d, int _n){
        n = _n;
        d = _d;
    };
    bool operator()(const Apple& lhs, const Apple& rhs){
        return (lhs.d > rhs.d);
    }
};
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<Apple,vector<Apple>,Apple> pq; 
        int n = apples.size();
        int count = 0;
        int j = 0;
        while (j < n || !pq.empty()){
            
            if (j < n && apples[j] > 0){
                pq.push(Apple(j + days[j] - 1,apples[j]));
            }
            while (!pq.empty() && (pq.top().d < j || pq.top().n == 0)){
                
                pq.pop();
            }
            if (!pq.empty()){
                count++;
                Apple top  = pq.top();
                pq.pop();
                top.n--;
                pq.push(top);
            }
            j++;
        }
        return count;
    }
};