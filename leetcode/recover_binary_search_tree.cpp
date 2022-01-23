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
    void inorder(TreeNode* root,vector<TreeNode*>& sequence){
        if (root==NULL){return;}
        if (root->left == NULL && root->right == NULL){
            sequence.push_back(root);
            return;
        }
        inorder(root->left,sequence);
        sequence.push_back(root);
        inorder(root->right,sequence);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> v;
        inorder(root,v);
        int firstIdx;
        for (int j = 1; j < v.size(); j++){
            if (v[j]->val<v[j-1]->val){
                firstIdx = j-1;
                break;
            }
        }
        int secondIdx = firstIdx + 1;
        for (int j = secondIdx; j < v.size(); j++){
            if (v[j]->val < v[j-1]->val){
                secondIdx = j;
            }
        }
        int tmp = v[firstIdx]->val;
        v[firstIdx]->val = v[secondIdx]->val;
        v[secondIdx]->val = tmp;
    }
};