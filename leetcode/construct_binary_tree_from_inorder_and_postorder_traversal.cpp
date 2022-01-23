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
    
    TreeNode* build(vector<int>& postorder, vector<int>& inorder, int inStart, int inEnd, int& postIdx){
        if (postIdx == -1){return NULL;}
        if (inStart > inEnd){return NULL;}
        TreeNode* parent = new TreeNode(postorder[postIdx]);
        if (inStart == inEnd){
            postIdx--; 
            return parent;
        }
        int pos = search(inorder,inStart,inEnd,postorder[postIdx]);
        postIdx--;
        parent->right = build(postorder,inorder,pos+1, inEnd,postIdx);
        parent->left = build(postorder,inorder,inStart, pos-1,postIdx);
        return parent;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = postorder.size()-1;
        return build(postorder,inorder,0,inorder.size()-1,idx);
    }
};