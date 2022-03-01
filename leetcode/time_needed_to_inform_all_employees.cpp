struct Node{
    int costFromHead;
    int v;
    Node(){};
    Node(int cost, int _v){
        v = _v;
        costFromHead = cost;
    };
    bool operator()(const Node& lhs, const Node& rhs){
        return lhs.costFromHead < rhs.costFromHead;
    }
    
};

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        priority_queue<Node,vector<Node>,Node> pq;
        pq.push(Node(informTime[headID],headID));
        vector<vector<int>> adjList(n,vector<int>{});
        for (int j = 0; j < n; j++){
            if (j == headID){continue;}
            adjList[manager[j]].push_back(j);
        }
        int longestTime = informTime[headID];
        while (!pq.empty()){
            int curr = pq.top().v;
            int costFromHeadToCurr = pq.top().costFromHead;
            pq.pop();
            vector<int> subordinates = adjList[curr];
            for (int j = 0; j < subordinates.size(); j++){
                int subordinate = subordinates[j];
                int cost = costFromHeadToCurr + informTime[subordinate];
                if (cost > longestTime){longestTime = cost;}
                pq.push(Node(cost,subordinate));
            }
        }
        return longestTime;
    }
};