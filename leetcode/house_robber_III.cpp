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

typedef pair<int,int> ii;
class Solution {
public:
    
    ii robHouse(TreeNode* root){
        if (root == NULL){return ii(0,0);}
        if (root->left == NULL && root->right == NULL){
            return ii(root->val,0);
        }
        ii lp = robHouse(root->left);
        ii rp = robHouse(root->right);
        ii rootp(root->val + lp.second  + rp.second, max(lp.first, lp.second) + max(rp.first,rp.second));
        return rootp;
        
    }
    int rob(TreeNode* root) {
        ii rootp = robHouse(root);
        return max(rootp.first, rootp.second);
    }
};