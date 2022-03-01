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
    int max(int a, int b){
        if (a>b ){return a;}
        return b;
    }

    int maxSum(TreeNode* root, int& currMax, bool& isPicked, int& largest) {
        if (root == NULL){return 0;}
        if (root->left == NULL && root->right == NULL){
            if (root->val > largest ){largest = root->val;}
            return max(0,root->val);
        }
        int rootval = root->val;
        if (rootval>largest){largest = rootval;}
        int rval = maxSum(root->right,currMax,isPicked,largest);
        int lval = maxSum(root->left, currMax,isPicked,largest);
        int maxval = max(rootval + rval + lval, max(rval,lval));
        if (maxval > currMax){
            currMax = maxval;
        }
        if (rootval > 0 || rootval+rval > 0 || rootval+lval > 0){isPicked = true;}
        return max(max(rootval,0),max(rootval+rval,rootval+lval));
    }
    int maxPathSum(TreeNode* root) {
        if (root == NULL){return 0;}
        int currMax = root->val;
        bool isPicked = (currMax > 0) ? true : false;
        int largest = root->val;
        int x = maxSum(root,currMax,isPicked,largest);
        if (!isPicked){return largest;}
        return max(x,currMax);
        
    }
};