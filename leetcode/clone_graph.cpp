/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL){return NULL;}
        Node* nodes[101];
        nodes[node->val] = new Node(node->val);
        queue<Node*> q;
        q.push(node);
        vector<bool> isVisited(101,false);
        isVisited[node->val] = true;
        while (!q.empty()){
            Node *curr = q.front();
            q.pop();
            for (int j = 0; j < curr->neighbors.size(); j++){
                Node *next = curr->neighbors[j];
                if (!isVisited[next->val]){
                    isVisited[next->val] = true;
                    nodes[next->val] = new Node(next->val);
                    q.push(next);
                }
                nodes[curr->val]->neighbors.push_back(nodes[next->val]);
            }
        }
        
        
        return nodes[node->val];
    }
};