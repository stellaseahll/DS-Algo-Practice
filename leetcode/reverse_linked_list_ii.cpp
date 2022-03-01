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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right){return head;}
        ListNode* start;
        ListNode* end = head;
        for (int j = 1; j < right; j++){
            end = end->next;
        }
        if (left == 1){
            start = new ListNode(0);
            start-> next = head;
        }
        else{
            start = head;
            for (int j = 1; j < left-1; j++){
                start = start->next;
            }
        }
        ListNode* parent = end->next;
        ListNode* curr = start->next;
        for (int j = left; j <= right; j++){
            ListNode* tmp = curr->next;
            curr->next = parent;
            parent = curr; 
            curr = tmp;
        }
        start->next = parent;
        if (left == 1){return parent;}
        
        return head;   
    }
};