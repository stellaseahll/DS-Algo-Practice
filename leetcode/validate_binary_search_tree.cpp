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
    void inorder(TreeNode* root, vector<int>& sequence){
        if (root == NULL){
            return;
        }
        if (root -> left == NULL && root -> right == NULL){
            sequence.push_back(root->val);
            return;
        }
        inorder(root->left,sequence);
        sequence.push_back(root->val);
        inorder(root->right,sequence);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        for (int j = 1; j < v.size(); j++){
            if (v[j] <= v[j-1]){return false;}
        }
        return true;
    }
};