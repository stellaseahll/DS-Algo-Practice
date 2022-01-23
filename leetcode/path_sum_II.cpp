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
    void dfs(TreeNode* root, const int& targetSum, vector<int>& currPath, int curr, vector<vector<int>>& result){
        if (root == NULL){return;}
        if (root->left == NULL && root->right == NULL){
            if (curr == targetSum){
                result.push_back(currPath);
            }
            return;
        }
        if (root->left != NULL){
            currPath.push_back(root->left->val);
            dfs(root->left, targetSum, currPath, curr + root->left->val, result);
            currPath.pop_back();
        }
        if (root->right != NULL){
            currPath.push_back(root->right->val);
            dfs(root->right, targetSum,currPath, curr+ root->right->val, result);
            currPath.pop_back();
        }
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == NULL){return vector<vector<int>>{};}
       vector<vector<int>> result;
        vector<int> path = {root->val};
        dfs(root, targetSum, path, root->val, result);
        return result;
        
    }
};