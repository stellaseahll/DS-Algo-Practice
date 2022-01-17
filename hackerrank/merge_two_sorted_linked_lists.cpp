

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* curr1 = head1;
    SinglyLinkedListNode* curr2 = head2;
    SinglyLinkedListNode* newList = new SinglyLinkedListNode(0);
    SinglyLinkedListNode* curr = newList;
    while (curr1 != nullptr && curr2 != nullptr){
        SinglyLinkedListNode* newNode;
        if (curr1 -> data <= curr2 -> data){
            newNode = new SinglyLinkedListNode(curr1 -> data);
            curr1 = curr1 -> next;
        }
        else{
            newNode = new SinglyLinkedListNode(curr2 -> data);
            curr2 = curr2 -> next;
        }
        curr -> next = newNode;
        curr = curr -> next;
    }
    if (curr2 != nullptr){
        curr -> next = curr2;
    }
    else{
        curr -> next = curr1;
    }
    return newList->next;
}

