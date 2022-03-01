/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void connect2(Node* root){
        if (root == NULL){return;}
        if (root-> left == NULL && root->right == NULL){
            return;
        }
        if (root->left != NULL && root->right != NULL){
            root->left->next = root->right;
            if (root->next == NULL){
                root->right->next == NULL;
            }
            else{
                root->right->next = root->next->left;
            }
        }
        if (root->left != NULL && root-> right == NULL){
            root->left->next = NULL;
        }
        connect2(root->left);
        connect2(root->right);
    }
    
    Node* connect(Node* root) {
        if (root == NULL){return root;}
        root->next = NULL;
        connect2(root);
        return root;
    }
};