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
    TreeNode* construct(const vector<int>& preorder, const vector<int>& postorder, unordered_map<int,int>& preHash, unordered_map<int,int>& postHash, int preStart, int preEnd, int postStart, int postEnd){
        if (preEnd - preStart < 0){return NULL;}
        if (preEnd - preStart == 0){
            TreeNode* root = new TreeNode(preorder[preStart]);
            return root;
        }
        if (preEnd-preStart == 1){
            int rootval = preorder[preStart];
            int leftval = preorder[preEnd];
            TreeNode* root = new TreeNode(rootval);
            TreeNode* leftNode = new TreeNode(leftval);
            root->left = leftNode;
            return root;
        }
        int rootval = preorder[preStart];
        int rightval = postorder[postEnd-1];
        int leftval = preorder[preStart+1];
        int rightValIdx = preHash[rightval];
        int leftValIdx = postHash[leftval];
        TreeNode* root = new TreeNode(rootval);
        root->left = construct(preorder, postorder, preHash, postHash, preStart+1, rightValIdx-1, postStart, leftValIdx);
        root->right = construct(preorder, postorder, preHash, postHash, rightValIdx, preEnd, leftValIdx+1,postEnd-1);
        return root;
    }
    
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = postorder.size(); 
        if (n == 0){return NULL;}
        unordered_map<int,int> preHash, postHash;
        for (int j = 0; j < n; j++){
            preHash[preorder[j]] = j;
            postHash[postorder[j]] = j;
        }
        return construct(preorder, postorder, preHash, postHash, 0, n-1, 0, n-1);
    }
};