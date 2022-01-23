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
    int search(vector<int>& inorder, int inStart, int inEnd, int target){
        for (int j = inStart; j <= inEnd; j++){
            if (inorder[j] == target){return j;}
        }
        return -1;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd, int& preIdx){
        if (preIdx == preorder.size()){return NULL;}
        if (inStart > inEnd){return NULL;}
        TreeNode* parent = new TreeNode(preorder[preIdx]);
        if (inStart == inEnd){
            preIdx++; 
            return parent;
        }
        int pos = search(inorder,inStart,inEnd,preorder[preIdx]);
        preIdx++;
        parent->left = build(preorder,inorder,inStart, pos-1,preIdx);
        parent->right = build(preorder,inorder,pos+1, inEnd,preIdx);
        return parent;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return build(preorder,inorder,0,inorder.size(), idx);
    }
};