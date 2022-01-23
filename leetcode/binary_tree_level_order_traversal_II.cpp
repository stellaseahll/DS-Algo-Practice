/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
typedef pair<TreeNode*,int> ti;
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<ti> q;
        stack<pair<int,vector<int>>> s;
        q.push(ti(root,0));
        while (!q.empty()){
            ti curr = q.front();
            q.pop();
            int h = curr.second;
            TreeNode* node = curr.first;
            if (node == NULL){continue;}
            if (!s.empty() && s.top().first == h){
                s.top().second.push_back(node->val);
            }
            else{
                s.push(pair<int,vector<int>>(h, vector<int>(1,node->val)));
            }
            q.push(ti(node->left,h+1));
            q.push(ti(node->right,h+1));
        }
        vector<vector<int>> answer;
        while (!s.empty()){
            answer.push_back(s.top().second);
            s.pop();
        }
        return answer;
    }

};