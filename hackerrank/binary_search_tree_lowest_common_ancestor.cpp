#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/

    Node *lca(Node *root, int v1,int v2) {
		// Write your code here.
        if (v1 > v2){ // make v1 < v2 for convenience of comparison
            int tmp = v1;
            v1 = v2;
            v2 = tmp;
        }
        Node *curr = root;
        while (v1 > curr->data || v2 < curr->data){
            if (v1 > curr->data){
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
        return curr;
    }

}; //End of Solution