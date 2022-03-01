/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* getLastPointer(Node* head){
        Node* curr = head; 
        while (curr->next != NULL){
            curr = curr->next;
        }
        return curr;
    }
    
    Node* flatten(Node* head) {
        Node* curr = head;
        while (curr != NULL){
            if (curr->child != NULL){
                Node* child = curr->child;
                curr->child = NULL;
                Node* childEnd = getLastPointer(child);
                childEnd->next = curr->next;
                if (curr->next != NULL){
                    curr->next->prev = childEnd;
                }
                curr->next = child;
                child->prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};