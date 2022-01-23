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
typedef pair<int,int> ii;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> copy(lists.size(),NULL);
        if (lists.size() == 0){return NULL;}
        if (lists.size() == 1){return lists[0];}
        priority_queue<ii,vector<ii>,greater<ii>> pq;
        int n = lists.size();
        for (int j = 0; j < n; j++){
            if (lists[j] != NULL){
                pq.push(ii(lists[j]->val,j));
                copy[j] = lists[j]->next;
            }
        }
        ListNode* curr = new ListNode(0);
        ListNode* parent = curr;
        while (!pq.empty()){
            ListNode* tmp = new ListNode(pq.top().first);
            int idx = pq.top().second;
            if (copy[idx] != NULL){
                ii newPair(copy[idx]->val,pq.top().second);
                copy[idx] = copy[idx]->next;
                pq.pop();
                pq.push(newPair);
            }
            else{
                pq.pop();
            }
            curr->next = tmp;
            curr = curr->next;
            if (pq.empty()){
                
            }
        }
        return parent->next;
    }
};