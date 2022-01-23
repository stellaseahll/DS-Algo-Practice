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
    bool isLeafOrNull(TreeNode* root){
        if (root == NULL){return true;}
        if (root->left == NULL && root->right == NULL){return true;}
        return false;
    }
    bool isLeaf(TreeNode* root){
        if (root == NULL){return false;}
        if (root->left == NULL && root->right == NULL){return true;}
        return false;
    }
    int max(int a, int b){
        if (a>b){return a;}
        return b;
    }
    int getHeight(TreeNode* root){
        if (root == NULL){return 0;}
        if (isLeaf(root)){return 1;}
        return 1+max(getHeight(root->left), getHeight(root->right));
    }
    int abs(int x){
        if (x>0){return x;}
        return -x;
    }
    bool isBalanced(TreeNode* root){
        if (root == NULL){return true;}
        if (root->left == NULL){
            if (getHeight(root->right)>1){return false;}
            return true;
        }
        if (root->right == NULL){
            if (getHeight(root->left)>1){return false;}
            return true;
        }
        if (abs(getHeight(root->left) -getHeight(root->right))>1){return false;}
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
};