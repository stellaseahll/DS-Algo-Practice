struct Closest{
    int a; 
    int x; 
    int idx;
    Closest(){};
    Closest(int _a,int _x, int j){
        a = _a;
        x = _x;
        idx = j;
    };
    bool operator()(const Closest &lhs, const Closest &rhs){
        if (abs(lhs.a-lhs.x)==abs(rhs.a-rhs.x)){
            return lhs.a > rhs.a;
        }
        return abs(lhs.a-lhs.x)>abs(rhs.a-rhs.x);
    }
};
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<Closest,vector<Closest>,Closest> pq;
        vector<bool> isVisited(n,false);
        int idx = lower_bound(arr.begin(),arr.end(), x) - arr.begin();
        if (idx == 0){
            pq.push(Closest(arr[0],x,0));
        }
        else if (idx == n){
            pq.push(Closest(arr[n-1],x,n-1));
        }
        else{
            pq.push(Closest(arr[idx],x,idx));
            pq.push(Closest(arr[idx-1],x,idx-1));
        }
        vector<int> elements;
        while (!pq.empty() && k--){
            Closest curr = pq.top();
            pq.pop();
            elements.push_back(curr.a);
            if (curr.idx >= idx && curr.idx+1 < n){
                pq.push(Closest(arr[curr.idx+1],x,curr.idx+1));
            }
            else if (curr.idx < idx && curr.idx-1 >= 0){
                pq.push(Closest(arr[curr.idx-1],x,curr.idx-1));
            }
        }
        sort(elements.begin(),elements.end());
        return elements;
    }
};