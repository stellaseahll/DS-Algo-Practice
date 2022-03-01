struct Node{
    Node* child[27];
    Node(){
        for (int j = 0; j < 27; j++){
            child[j] = NULL;
        }
    }
    void insert(int x){
        if (child[x] == NULL){
            child[x] = new Node();
        }
        return;
    }
    
    void markEnd(){
        insert(26);
    }
    
    bool isLast(){
        return !(child[26] == NULL);
    }
};

class MagicDictionary {
private:
    Node *root;
public:
    MagicDictionary() {
        root = new Node();
    }
    void addWord(string s){
        Node *curr = root;
        for (int j = 0; j < s.size(); j++){
            char c = s[j];
            int idx = c-'a';
            curr->insert(idx);
            curr = curr->child[idx];
        }
        curr->markEnd();
    }
    void buildDict(vector<string> dictionary) {
        for (int j = 0; j < dictionary.size(); j++){
            addWord(dictionary[j]);
        }
        return;
    }
    bool searchRecursive(Node* curr, string word, bool isChanged){
        if (word.size()==0 && curr->child[26] == NULL){return false;}
        if (word.size()==0 && curr->child[26] != NULL){
            if (isChanged){return true;}           
            return false;
        }
        char c = word[0];
        int idx = c-'a';
        string shortenWord = word.substr(1,word.size()-1);
        if (isChanged && curr->child[idx] == NULL){return false;}
        if (isChanged){
            return searchRecursive(curr->child[idx],shortenWord,isChanged);
        }
        if (curr->child[idx] != NULL){
            bool noChangeExist = searchRecursive(curr->child[idx],shortenWord,isChanged);
            if (noChangeExist){return true;}
        }
        for (int j = 0; j < 26; j++){
            if (j == idx){continue;}
            if (curr->child[j] != NULL){
                bool changeExist = searchRecursive(curr->child[j],shortenWord,true);
                if (changeExist){return true;}
            }
        }
        return false;
        
    }
    bool search(string searchWord) {
        bool isChanged = false;
        return searchRecursive(root,searchWord,isChanged);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */