#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'noPrefix' function below.
 *
 * The function accepts STRING_ARRAY words as parameter.
 */
class Node{
    vector<Node*> letterNodes;
    public:
    bool isLeaf;
    Node(){
        isLeaf = true;
        for (int j = 0; j < 10; j++){
            letterNodes.push_back(NULL);
        }
    }
    Node(char c){
        isLeaf = true;
        for (int j = 0; j < 10; j++){
            letterNodes.push_back(NULL);
        }
        letterNodes[c-'a'] = new Node();
    }
    bool isExist(char c){
        if (letterNodes[c-'a'] != NULL){
            return true;
        }
        return false;
    }
    void append(char c){
        isLeaf = false;
        letterNodes[c-'a'] = new Node();
    }  
    Node* nextIndex(char c){
        return letterNodes[c-'a'];
    }
};

void noPrefix(vector<string> words) {
    Node * root = new Node();
    for (int j = 0 ; j < words.size(); j++){
        Node *curr = root;
        bool isSame = true;
        for (int k = 0; k < words[j].size(); k++){
            char c = words[j][k];
            if (!curr->isExist(c)){
                curr->append(c);
                isSame = false;
            }
            else if (isSame && curr->nextIndex(c)->isLeaf){
                cout << "BAD SET" <<endl << words[j] << endl;
                return;
            }
            curr = curr->nextIndex(c);
        }
        if (isSame){cout << "BAD SET" <<endl << words[j] << endl; return;}   
    }
    cout << "GOOD SET" << endl; 
    return;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        string words_item;
        getline(cin, words_item);

        words[i] = words_item;
    }

    noPrefix(words);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
