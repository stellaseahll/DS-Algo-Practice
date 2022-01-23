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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> s;
        ListNode* curr=head;
        while (curr!=NULL){
            s.push(new ListNode(curr->val));
            curr = curr->next;
        }
        ListNode* parent = NULL;
        for (int j = 0; j < n-1; j ++){
            s.top()->next = parent;
            parent = s.top();
            s.pop();
        }
        s.pop();
        while (!s.empty()){
            s.top()->next = parent;
            parent = s.top();
            s.pop();
        }
        return parent;
    }
};