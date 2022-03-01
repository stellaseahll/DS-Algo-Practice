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
    void sumNodes(TreeNode* root, int low, int high, int& currSum){
        if (root == NULL){return;}
        if (root->val >= low && root->val <= high){
            currSum += root->val;
        }
        if (root->left != NULL){
            sumNodes(root->left,low,high,currSum);
        }
        if (root->right != NULL){
            sumNodes(root->right,low,high,currSum);
        }
        
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int currSum = 0;
        sumNodes(root,low,high,currSum);
        return currSum;
    }
};