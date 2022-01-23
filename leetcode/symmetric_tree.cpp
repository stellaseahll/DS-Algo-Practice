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
    bool isLeaf(TreeNode* root){
        if (root == NULL) {return false;}
        if (root->left == NULL && root->right == NULL){return true;}
        return false;
    }
    bool isSymmetric(TreeNode* p, TreeNode* q){
        if (p == NULL && q == NULL){return true;}
        if (p == NULL ^ q == NULL){return false;}
        if (isLeaf(p) ^ isLeaf(q)){return false;}
        if (p->val != q->val){return false;}
        return isSymmetric(p->left,q->right) && isSymmetric(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root->left, root->right);
    }
};