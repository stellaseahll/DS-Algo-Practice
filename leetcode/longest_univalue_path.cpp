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
    ii countRepeat(TreeNode* root, int& currMax){
        if (root == NULL){
            return (ii(0,0));
        }
        if (root->left == NULL && root->right == NULL){
            return (ii(root->val, 1));
        }
        ii leftp = countRepeat(root->left, currMax);
        ii rightp = countRepeat(root->right, currMax);
        if (root->val == leftp.first && root->val == rightp.first){
            currMax = max(currMax, leftp.second + rightp.second);
            return ii(root->val, max(leftp.second,rightp.second)+1);
        }
        else if (root->val == leftp.first){
            currMax = max(currMax, leftp.second);
            return ii(root->val, leftp.second+1);
        }
        else if (root->val == rightp.first){
            currMax = max(currMax, rightp.second);
            return ii(root->val, rightp.second+1);
        }
        return ii(root->val,1);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        int currMax = 0;
        countRepeat(root, currMax);
        return currMax;
    }
};