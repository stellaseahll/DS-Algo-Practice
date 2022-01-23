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
    TreeNode* arrayToBST(vector<int>& nums, int start, int end) {
        if (start > end){return NULL;}
        if (start == end){return new TreeNode(nums[start]);}
        int mid = (end+start)/2;
        TreeNode* parent = new TreeNode(nums[mid]);
        parent -> left = arrayToBST(nums, start, mid-1);
        parent -> right = arrayToBST(nums, mid+1, end);
        return parent;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0){return NULL;}
        return arrayToBST(nums,0,nums.size()-1);
    }
};