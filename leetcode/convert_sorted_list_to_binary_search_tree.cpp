/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* listToBST(ListNode* head, int start, int end){
        if (start > end){
            return NULL;
        }
        if (start == end){
            if (head == NULL){return NULL;}
            return new TreeNode(head->val);
        }
        int mid = (end+start)/2;
        int j = start+1;
        ListNode *left, *right, *cleft, *cright;
        left = head;
        cleft = head;
        while (j++ < mid){
            cleft = cleft->next;
        }
        TreeNode* parent = new TreeNode(cleft->next->val);
        right = cleft->next->next;
        cleft->next = NULL;
        int mid1 = (mid-1 < start) ? start : mid-1;
        int mid2 = (mid+1 > end) ? end : mid+1;
        parent->left = listToBST(left,start,mid1);
        parent->right = listToBST(right,mid2,end);
        return parent;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL){return NULL;}
        int count = 0;
        ListNode* tmp = head;
        while (tmp ->next !=NULL){
            tmp = tmp->next;
            count++;
        }
        return listToBST(head, 0, count);
    }
};