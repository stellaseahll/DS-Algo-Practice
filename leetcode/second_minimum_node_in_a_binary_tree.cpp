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
    void findSecondMin(TreeNode* root, int target, int& curr, bool& isFound){
        if (root == NULL){return;}
        if (isLeaf(root)){return;}
        if (root->val == root->left->val){
            if (root->right->val > target){
                curr = min(root->right->val,curr);
                isFound = true;
            }
            findSecondMin(root->left,target,curr,isFound);
        }
        if (root->val == root->right->val){
            if (root->left->val > target){
                curr = min(curr,root->left->val);
                isFound = true;
            }
            findSecondMin(root->right,target,curr,isFound);
        }
        return;
    }
    int findSecondMinimumValue(TreeNode* root) {
        int curr = INT_MAX;
        bool isFound = false;
        findSecondMin(root,root->val,curr,isFound);
        if (isFound){
            return curr;
        }
        return -1;
    }
};