

/* 
The structure of the node is

typedef struct node {

	int freq;
    char data;
    node * left;
    node * right;
    
} node;

*/


void decode_huff(node * root, string s) {
    node * curr = root;
    for (int j = 0; j < s.length(); j++){
        if (s[j] == '0'){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
        if (curr->left == NULL && curr->right == NULL){
            cout << curr->data;
            curr = root;
        }
    }
}

