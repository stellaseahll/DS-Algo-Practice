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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL){return head;}
        if (head->next == NULL){return head;}
        ListNode* parent = head->next;
        ListNode* curr = head;
        curr->next = parent->next;
        parent->next = curr;
        while (curr->next != NULL && curr->next->next != NULL){
            ListNode* tmp = curr->next;
            curr->next = tmp->next;
            tmp->next = tmp->next->next;
            curr->next->next = tmp;
            curr = curr->next->next;
        }   
        return parent;

        
        
    }
};