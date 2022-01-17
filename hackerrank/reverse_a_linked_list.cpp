

/*
 * Complete the 'reverse' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    // vector<SinglyLinedListNode> v;
    SinglyLinkedListNode* currPtr = llist;
    SinglyLinkedListNode* answer = NULL;
    while (currPtr != NULL){
        SinglyLinkedListNode *tmp;
        tmp = new SinglyLinkedListNode(currPtr->data);
        tmp->next = answer;
        answer = tmp;
        currPtr = currPtr->next;
    }
    return answer;
}

