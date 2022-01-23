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
    bool isLeaf(TreeNode* p){
        if (p == NULL){return false;}
        if (p->left == NULL && p->right == NULL){return true;}
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL){return true;}
        if (p == NULL ^ q == NULL){return false;}
        if (isLeaf(p) ^ isLeaf(q)){return false;}
        if (p->val == q->val){
            return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }
        else{
            return false;
        }
        
    }
};