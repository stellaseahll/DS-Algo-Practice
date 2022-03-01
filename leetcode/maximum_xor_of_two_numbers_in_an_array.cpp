struct Node{
    Node *child[2];
    Node(){
        child[0] = NULL;
        child[1] = NULL;
    };
    void insert(int x){
        if (child[x] == NULL){
            child[x] = new Node();
        }
        return;
    }
    bool isEnd(){
        if (child[0] == NULL && child[1] == NULL){
            return true;
        }
        return false;
    }
};

class Solution {
    Node *root;
public:
    Solution(){
        root = new Node();
    }
    void addNumber(int x){
        Node *curr = root;
        for (int j = 30; j >= 0; j--){
            int currBit = 1 << j;
            if (currBit & x){
                curr->insert(1);
                curr = curr->child[1];
            }
            else{
                curr->insert(0);
                curr = curr->child[0];
            }
        }
    }
    int getMaxXOR(int x){
        Node *curr = root;
        int currSum = 0;
        for (int j = 30; j >= 0; j--){
            int currBit = 1 << j;
            if (currBit & x){
                if (curr->child[0] == NULL){
                    curr = curr->child[1];
                }
                else{
                    currSum += currBit;
                    curr = curr->child[0];
                }
            }
            else{
                if (curr->child[1] == NULL){
                    curr = curr->child[0];
                }
                else{
                    currSum += currBit;
                    curr = curr->child[1];
                }
            }
        }
        return currSum;
        
    }
    int findMaximumXOR(vector<int>& nums) {
        for (int j = 0; j < nums.size(); j++){
            addNumber(nums[j]);
        }
        int currMax = 0;
        for (int j = 0; j < nums.size(); j++){
            int max = getMaxXOR(nums[j]);
            if (max > currMax){currMax = max;}
        }
        return currMax;
    }
};