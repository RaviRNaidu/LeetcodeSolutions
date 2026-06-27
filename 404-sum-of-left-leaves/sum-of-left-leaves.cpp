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
        if(node->left == NULL && node->right == NULL) return true;
        return false;
    }

    void traversal(TreeNode* root, int &sum){
        if(root != NULL){
            if(root->left != NULL && isLeaf(root->left)){
                sum += root->left->val;
            }
            traversal(root->left, sum);
            traversal(root->right, sum);
        }
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        traversal(root, sum);
        return sum;
    }
};