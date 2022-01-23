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
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& store){
        if (root == NULL){return;}
        if (root -> left == NULL && root->right == NULL){
            store.push_back(root->val);
            return;
        }
        inorder(root->left,store);
        store.push_back(root->val);
        inorder(root->right,store);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer; 
        inorder(root, answer);
        return answer;
    }
};