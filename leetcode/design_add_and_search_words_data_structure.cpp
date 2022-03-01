struct Node{
    Node* child[27];
    bool isLeaf;
    Node(){
        isLeaf = true;
        for (int j = 0; j < 27; j++){
            child[j] = NULL;
        }
    }
    void insert(int x) {
        if (child[x] == NULL){
            child[x] = new Node();
            isLeaf = false;
        }
        return;
    }
    void markEnd(){
        child[26] = new Node();
        isLeaf = false;
    }
    bool isLast(){
        if (child[26]!= NULL){return true;}
        return false;
    }
};

class WordDictionary {

private:
    Node *root;

public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node *curr = root;
        for (int j = 0; j < word.size(); j++){
            char c = word[j];
            if (c >= 'a' && c <= 'z'){
                int currC = c-'a';
                curr->insert(currC);
                curr = curr->child[currC];
            }
        }
        curr->markEnd();
        return;
    }
    
    bool searchWord(string word, Node* root){
        Node* curr = root;
        int n = word.size();
        for (int j = 0; j < n; j++){
            char c = word[j];
            if (c == '.'){
                string s = word.substr(j+1,n-1-j);
                for (int k = 0; k < 26; k++){  
                    if (curr->child[k] != NULL){
                        if (searchWord(s,curr->child[k])){return true;}
                    }
                }
                return false;
            }
            else{
                int currC = c-'a';
                if (curr->child[currC] == NULL){return false;}  
                curr = curr->child[currC];
            }
        }
        if (curr->isLast()){return true;}
        return false;
    }
    
    bool search(string word) {
        return searchWord(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */