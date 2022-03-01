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
typedef pair<TreeNode*, TreeNode*> tt;
class Solution {
public:
    bool isLeaf(TreeNode* root){
        if (root == NULL){return false;}
        if (root->left == NULL && root->right == NULL){return true;}
        return false;
    }
        tt flat(TreeNode* root) {
        if (root == NULL){return tt(NULL,NULL);}
        if (isLeaf(root->left) && isLeaf(root->right)){
            root->left->right = root->right;
            root->right = root->left;
            root->left = NULL;
            return tt(root,root->right->right);
        }
        if (root->left == NULL && root->right == NULL){return tt(root,root);}
        if (root->right == NULL){
            root->right = root->left;
            root->left = NULL;
        }
        if (root->left == NULL){
            tt right; 
            right = flat(root->right);
            root->right = right.first;
            return tt(root,right.second);
        }
        tt left, right;
        left = flat(root->left);
        right = flat(root->right);
        left.second->right = right.first;
        root->left = NULL;
        root->right = left.first;
        return tt(root, right.second);
        
    }
//     tt flat(TreeNode* root) {
//         if (root == NULL){return tt(NULL,NULL);}
//         if (isLeaf(root->left) && isLeaf(root->right)){
//             root->right->right = root->left;
//             root->left = NULL;
//             return tt(root,root->right->right);
//         }
//         if (root->left == NULL && root->right == NULL){return tt(root,root);}
//         if (root->right == NULL){
//             root->right = root->left;
//             root->left = NULL;
//         }
//         if (root->left == NULL){
//             tt right; 
//             right = flat(root->right);
//             root->right = right.first;
//             return tt(root,right.second);
//         }
//         tt left, right;
//         left = flat(root->left);
//         right = flat(root->right);
//         right.second->right = left.first;
//         root->left = NULL;
//         root->right = right.first;
//         return tt(root, right.second);
        
//     }
    void flatten(TreeNode* root) {
        tt res = flat(root);
           root = res.first;
    }
};