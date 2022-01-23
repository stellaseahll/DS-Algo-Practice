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
        if (root == NULL){return false;}
        if (root->left == NULL && root->right == NULL){return true;}
        return false;
    }
    
    bool dfs(TreeNode* root, const int& targetSum, int currSum){
        if (root == NULL){
            return false;
        }
        if (isLeaf(root)){
            if (currSum + root->val == targetSum){return true;}
            return false;
        }
        currSum += root->val;
        return dfs(root->left, targetSum, currSum) || dfs(root->right, targetSum, currSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL){return false;}
        return dfs(root,targetSum,0);
    }
};