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
    void dfsSum(TreeNode* root, int currSum, int& totalSum){
        if (root ->left == NULL && root->right == NULL){
            totalSum += (currSum*10 + root->val);
            return;
        }
        if (root->left != NULL){
            dfsSum(root->left, currSum*10 + root->val, totalSum);
        }
        if (root->right != NULL){
            dfsSum(root->right, currSum*10 + root->val, totalSum);
        }
        return;
    }
    
    int sumNumbers(TreeNode* root) {
        int total = 0;
        dfsSum(root, 0, total);
        return total;
    }
};