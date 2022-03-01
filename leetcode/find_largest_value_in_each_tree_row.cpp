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
typedef pair<TreeNode*,int> Ti;
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<Ti> q;
        if (root == NULL){return vector<int>{};}
        q.push(Ti(root,0));
        vector<int> answer;
        while (!q.empty()){
            TreeNode* curr = q.front().first;
            int level = q.front().second; 
            q.pop();
            if (answer.size() <= level){
                answer.push_back(curr->val);
            }
            else{
                answer[level] = max(answer[level],curr->val);
            }
            if (curr->left != NULL){
                q.push(Ti(curr->left,level+1));
            }
            if (curr->right != NULL){
                q.push(Ti(curr->right,level+1));
            }
        }
        return answer;
        
        
    }
};