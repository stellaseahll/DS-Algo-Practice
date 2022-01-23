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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr = new ListNode(0);
        ListNode* parent = curr;
        ListNode *ptr1 = list1, *ptr2 = list2;
        while (!ptr1 == NULL && !ptr2 == NULL){
            ListNode* newNode;
            if (ptr1->val < ptr2->val){
                newNode = new ListNode(ptr1->val);
                ptr1 = ptr1->next;
            }
            else{
                newNode = new ListNode(ptr2->val);
                ptr2 = ptr2->next;
            }
            curr->next = newNode;
            curr = curr->next;

        }
        if (ptr1 != NULL){
            curr->next = ptr1;
        }
        if (ptr2 != NULL){
            curr->next = ptr2;
        }
        return parent->next;
    }
};