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
    
    vector<TreeNode*> generateTrees(int n , int start, int end){
        if (n==0){  
            vector<TreeNode*> answer;
            answer.push_back(NULL);
            return answer;;
        }
        if (n==1){
            vector<TreeNode*> answer;
            answer.push_back(new TreeNode(start));
            return answer;
        }
        vector<TreeNode*> answer;
        for (int j = start; j <= end; j++){
            int nl = j-start, nr = end-j;
            vector<TreeNode*> leftNodes = generateTrees(nl,start,j-1);
            vector<TreeNode*> rightNodes = generateTrees(nr,j+1,end);
            for (int k = 0; k < leftNodes.size(); k++){
                for (int m = 0; m < rightNodes.size(); m++){
                    TreeNode *parent = new TreeNode(j);
                    parent -> left = leftNodes[k];
                    parent -> right = rightNodes[m];
                    answer.push_back(parent);
                }
            }
        }
        return answer;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(n, 1,n);
    }
};