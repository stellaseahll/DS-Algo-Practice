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
    void inOrder(TreeNode* root, vector<int>& sequence, const int& target){
        if (sequence.size() == target){return;}
        if (root == NULL){return;}
        inOrder(root->left, sequence, target);
        sequence.push_back(root->val);
        inOrder(root->right, sequence, target);
        
        
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> sequence;
        inOrder(root,sequence,k);
        return sequence[k-1];
    }
};