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
typedef pair<TreeNode*,int> ti;
class Solution {
public:
    bool isLeaf(TreeNode* root){
        if (root == NULL){return false;}
        if (root->left == NULL && root->right == NULL){return true;}
        return false;
    }
    int max(int a, int b){
        if (a>b){return a;}
        return b;
    }
    
    int getHeight(TreeNode* root){
        if (root == NULL){return 0;}
        if (isLeaf(root)){return 1;}
        return 1+max(getHeight(root->left),getHeight(root->right));
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL){
            return vector<vector<int>>{};
        }
        vector<vector<int>> answer(getHeight(root),vector<int>{});
        queue<ti> q;
        q.push(ti(root,0));
        while (!q.empty()){
            ti curr = q.front();
            q.pop();
            answer[curr.second].push_back(curr.first->val);
            if (curr.first->left != NULL){
                q.push(ti(curr.first->left, curr.second+1));
            }
            if (curr.first->right != NULL){
                q.push(ti(curr.first->right, curr.second+1));  
            }
        }

        return answer;
    }
};