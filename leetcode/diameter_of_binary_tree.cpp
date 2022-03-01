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
    ii getPath(TreeNode* root, int& maxLength){
        if (root == NULL || (root->left == NULL && root->right == NULL)){
            return ii(0,0);
        }
        int pathLength;
        int maxPath;
        if (root->right == NULL){
            ii leftPath = getPath(root->left,maxLength);
            pathLength = 1+leftPath.second;
            maxPath = pathLength;
        }
        else if (root->left == NULL){
            ii rightPath = getPath(root->right,maxLength);
            pathLength = 1+rightPath.second;
            maxPath = pathLength;
        }
        else{
            ii leftPath = getPath(root->left,maxLength);
            ii rightPath = getPath(root->right,maxLength);
            pathLength = 2+leftPath.second+rightPath.second;
            maxPath = 1+max(leftPath.second,rightPath.second);
        }
        if (pathLength > maxLength ){maxLength = pathLength;}
        return ii(pathLength,maxPath);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxLength = 0;
        getPath(root,maxLength);
        return maxLength;
    }
};