/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    int upperBound(const vector<int>& arr, int left, int right, int target){
        if (left > right ){return left;}
        int mid = (left + right)/2;
        if (arr[mid]  <  target){
            return upperBound(arr,mid+1,right,target);
        }
        return upperBound(arr,left,mid-1,target);
    }
    
    void preorder(TreeNode* root, vector<int>& sequence){
        if (root == NULL){return;}
        sequence.push_back(root->val);
        preorder(root->left,sequence);
        preorder(root->right,sequence);
        
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<int> sequence;
        preorder(root,sequence);
        string s = "";
        stringstream ss;
        for (int j = 0 ; j < sequence.size(); j++){
            ss << sequence[j] << " ";
        }
        return ss.str();
        
        
    }
    vector<int> getPreOrder(string s){
        stringstream ss;
        ss << s;
        vector<int> preOrder;
        int x;
        while (ss >> x){
            preOrder.push_back(x);
        }
        return preOrder;
        
    }
    TreeNode* build(const vector<int>& arr, int left, int right){
        if (left > right){
            return NULL;
        }
        if (left == right){
            return new TreeNode(arr[left]);
        }
        int rootVal = arr[left];
        TreeNode* root = new TreeNode(rootVal);
        int mid = upperBound(arr, left+1, right, rootVal);
        root->left = build(arr,left+1,mid-1);
        root->right = build(arr,mid,right);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> pre = getPreOrder(data);
        int n = pre.size();
        TreeNode* root = build(pre, 0, n-1);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;