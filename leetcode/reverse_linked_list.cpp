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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL){return head;}
        ListNode* curr  = head->next;
        ListNode* tail = head;
        tail->next = NULL;
        while (curr != NULL){
            ListNode* tmp = curr->next;
            curr->next = tail;
            tail = curr;
            curr = tmp;
        }
        return tail;
    }
};