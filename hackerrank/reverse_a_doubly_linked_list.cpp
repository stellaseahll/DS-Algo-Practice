

/*
 * Complete the 'reverse' function below.
 *
 * The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
 * The function accepts INTEGER_DOUBLY_LINKED_LIST llist as parameter.
 */

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */

DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode* currPtr = llist;
    DoublyLinkedListNode* answer = NULL;
    while (currPtr != NULL){
        DoublyLinkedListNode *tmp;
        tmp = new DoublyLinkedListNode(currPtr->data);
        tmp->next = answer;
        tmp->prev = NULL;
        if (answer!= NULL){
            answer->prev = tmp;
        }
        answer = tmp;
        currPtr = currPtr->next;
    }
    return answer;

}

