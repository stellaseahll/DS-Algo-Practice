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
    TreeNode* build(const vector<int>& preorder, int start, int end) {
        if (start>end){
            return NULL;
        }
        if (start==end){
            return new TreeNode(preorder[start]);
        }
        int rootval = preorder[start];
        TreeNode* root = new TreeNode(rootval);
        int idx = end;
        for (int j = start; j <= end; j++){
            if (preorder[j]>rootval){
                idx = j-1;
                break;
            }
        }
        root->left = build(preorder, start+1, idx);
        root->right = build(preorder, idx+1, end);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size()==0){return NULL;}
        return build(preorder,0,preorder.size()-1);
    }
};