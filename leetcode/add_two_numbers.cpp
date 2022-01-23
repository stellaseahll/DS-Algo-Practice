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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *currNode = new ListNode(),*prevNode, *answer = currNode;
        int residue = 0;
        while (l1 != NULL || l2 != NULL){
            int l1Val = (l1 == NULL) ? 0 : l1->val;
            int l2Val = (l2 == NULL) ? 0 : l2->val;
            int value = l1Val + l2Val + residue;
            residue = value/10;
            currNode -> val = value%10;
            l1 = (l1 == NULL) ? NULL : l1 -> next;
            l2 = (l2 == NULL) ? NULL : l2 -> next;
            currNode -> next = new ListNode();
            prevNode = currNode;
            currNode = currNode -> next;
        }
        if (residue>0){
            currNode -> val = residue;
        }
        else{
            prevNode -> next = NULL;
        }
        return answer;
    }
};