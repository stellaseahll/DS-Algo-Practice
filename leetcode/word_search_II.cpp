vector<vector<int>> neighbors = {{0,1},{0,-1},{1,0},{-1,0}};
struct Node{
    Node* child[27];
    Node* parent;
    int numChild = 0;
    void insert(int idx, Node* p){
        if (child[idx] == NULL){
            child[idx] = new Node();
            child[idx]->parent = p;
            numChild++;
        }
        return;
    }
    void markEnd(Node* p){
        insert(26,p);
        return;
    }
    
    void unmarkEnd(){
        return deleteChar(26);
    }
    void deleteChar(int idx){
        if (child[idx] != NULL){
            child[idx] = NULL;
            numChild--;
        }
    }
    
    bool isChar(int idx){
        return !(child[idx] == NULL);
    }
    
    bool isEnd(){
        return isChar(26);
    }
};

class Solution {
private:
    Node* root;
    int M; 
    int N;
public:
    Solution(){
        root = new Node();
    }
    
    void addWord(string word){
        Node* curr = root;
        curr->parent = NULL;
        for (int j = 0; j < word.size(); j++){
            int idx = word[j] - 'a';
            curr->insert(idx,curr);
            curr = curr->child[idx];
        }
        curr->markEnd(curr);
        return;
    }
    
    void addDict(vector<string>& dict){
        for (int j = 0; j < dict.size(); j++){
            addWord(dict[j]);
        }
    }
    
    void deleteWord(vector<char>& word, Node* curr){
        curr->unmarkEnd();
        int j = word.size()-1;
        while (curr->parent != NULL && curr->numChild == 0){
            char c = word[j--];
            int idx = c-'a';
            Node* tmp = curr->parent;
            tmp->unmarkEnd();
            tmp->deleteChar(idx);
            curr = tmp;
        }
    }
    
    string charToString(const vector<char>& currWord){
        string s = "";
        for (int j = 0; j < currWord.size(); j++){
            s = s + currWord[j];
        }
        return s;
    }
    
    
    void dfs(const vector<vector<char>>& board, int i, int j, Node* curr, vector<char> currWord, set<string>& allWords, vector<vector<bool>>& isVisited){
        if (curr == NULL) {return;}
        if (curr->isEnd()){
            deleteWord(currWord,curr);
            allWords.insert(charToString(currWord));
        }
        if (isVisited[i][j]){return;}
        isVisited[i][j] = true;
        for (int k = 0; k < 4; k++){
            int x = i + neighbors[k][0];
            int y = j + neighbors[k][1];
            if (x < 0 || x >= M) {continue;}
            if (y < 0 || y >= N) {continue;}
            int idx = board[x][y]-'a';
            if (curr->child[idx] != NULL && !isVisited[x][y]){
                // isVisited[x][y] = true;
                currWord.push_back(board[x][y]);
                dfs(board, x, y, curr->child[idx], currWord, allWords,isVisited);
                currWord.pop_back();
                isVisited[x][y] = false;
            }
        }
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        addDict(words);
        M = board.size();
        N = board[0].size();
        set<string> allWords;
        for (int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                int idx = board[i][j]-'a';
                if (root->isChar(idx)){
                    vector<vector<bool>> isVisited(M, vector<bool>(N,false));
                    vector<char> currWord = {board[i][j]};
                    dfs(board, i, j, root->child[idx], currWord, allWords, isVisited);
                }
            }
        }
        vector<string> ans;
        for (set<string>::iterator it = allWords.begin(); it!= allWords.end(); it++){
            ans.push_back(*it);
        }
        return ans;
    }
};