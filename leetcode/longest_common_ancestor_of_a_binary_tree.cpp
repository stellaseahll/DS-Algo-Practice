/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findNode(TreeNode* root, TreeNode* target, vector<TreeNode*>& answer, vector<TreeNode*>& currNodes){
        if (root == NULL){
            return;
        }
        currNodes.push_back(root);
        if (target == root){
            answer = currNodes;
            return;
        }
        if (root->left != NULL){
            findNode(root->left, target, answer, currNodes);
            currNodes.pop_back();
        }
        if (root->right != NULL){
            findNode(root->right, target, answer, currNodes);
            currNodes.pop_back();
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pNodes,qNodes;
        vector<TreeNode*> curr = {};
        findNode(root,p,pNodes,curr);
        curr = {};
        findNode(root,q,qNodes,curr);
        int n = min(pNodes.size(),qNodes.size());
        for (int j = 0; j < n; j++){
            if (pNodes[j] != qNodes[j]){
                return pNodes[j-1];
            }
        }
        return pNodes[n-1];
    }
};