/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    private:
    vector<int> inOrder;
    int index = -1;
public:
    BSTIterator(TreeNode* root) {
        traversal(root, inOrder);
    }
    
    void traversal(TreeNode* root, vector<int> &arr){
        if(root != NULL){
            traversal(root->left, arr);
            arr.push_back(root->val);
            traversal(root->right, arr);
        }
    }

    int next() {
        return inOrder[++index];
    }
    
    bool hasNext() {
        if(index == inOrder.size() - 1) return false;
        else return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */