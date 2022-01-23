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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1 || head == NULL || head->next == NULL){return head;}
        ListNode* remaining = head;
        stack<ListNode*> s;
        for (int j = 0 ; j < k; j++){
            if (remaining!=NULL){
                s.push(remaining);
                remaining = remaining->next;
            }
        }
        
        ListNode *curr =  new ListNode(0);
        ListNode *parent = curr;
        
        while (s.size() == k){
            for (int j = 0 ; j < k; j++){
                
                curr->next = s.top();
                curr = curr->next;
                s.pop();
            }

            head = remaining;
            for (int j = 0 ; j < k; j++){
                if (remaining!=NULL){
                    s.push(remaining);
                    remaining = remaining->next;
                }
            }
            
        }
        
        if (s.size() < k){
            curr->next = head;
        }
        else{
            curr->next = NULL;
        }
        return parent->next;
        
        
    }
};