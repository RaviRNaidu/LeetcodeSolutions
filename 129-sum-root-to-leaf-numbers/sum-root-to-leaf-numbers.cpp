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
class Solution {
    bool isLeaf(TreeNode* node){
        if(node == NULL) return false;
        return node->left == NULL && node->right == NULL;
    }
    
    void preOrder(TreeNode* root, int& ans, int sum){
        if(root == NULL) return;
        if(isLeaf(root)){
            ans += (sum + root->val);
            return;
        }

        sum += root->val;
        sum *= 10;
        preOrder(root->left, ans, sum);
        preOrder(root->right, ans, sum);
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        preOrder(root, ans, 0);
        return ans;
    }
};