struct Node{
    Node* child[27];
    Node(){
        for (int j = 0; j < 27; j++){
            child[j] = NULL;
        } 
    }
    void insert(int i){
        if (child[i] == NULL){
            child[i] = new Node();
        }
        return;
    }
    void markEnd(){
        insert(26);
        return;
    }
    bool isEnd(){
        return isChar(26);
    }
    bool isChar(int idx){
        return !(child[idx] == NULL);
    }
};


class Solution {
private: 
    Node *root;
public:
    
    Solution(){
        root = new Node();   
    }
    
    void insertWord(string s){
        Node *curr = root;
        for (int j = 0 ; j < s.size(); j++){
            int idx = s[j]-'a';
            curr->insert(idx);
            curr = curr->child[idx];
        }
        curr->markEnd();
    }
    string convertString(const vector<string>& currString){
        string s = "";
        for (int j = 0; j < currString.size(); j++){
            s = s + currString[j] + " ";
        }
        return s.substr(0,s.size()-1);
    }
    void checkWord(string s, vector<string>& currString, vector<string>& allString){
        vector<string> answers;
        queue<int> q;
        if (s == ""){
            allString.push_back(convertString(currString));
            return;
        }
        int n = s.size();
        int j = 0;
        Node *curr = root;
        while (j<=n){
            if (curr->isEnd()){
                currString.push_back(s.substr(0,j));
                string word = s.substr(j,n-j);
                checkWord(word, currString, allString);
                currString.pop_back();
            }
            if (j == n){break;}
            int idx = s[j]-'a';
            if (curr->isChar(idx)){
                curr = curr->child[idx];
                j++;
            }
            else{
                break;
            }
        }
        return;
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (int j = 0; j < wordDict.size(); j++){
            insertWord(wordDict[j]);
        }
        vector<string> currString, allString;
        checkWord(s,  currString,  allString);
        return allString;
    }
};