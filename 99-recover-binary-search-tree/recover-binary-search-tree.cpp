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
    void traversal(TreeNode* root, TreeNode* &prev, TreeNode* &m1, TreeNode* &n1, TreeNode* &m2){
        if(root != NULL){
            traversal(root->left, prev, m1, n1, m2);
            if(prev != NULL && prev->val > root->val){
                if(m1 == NULL) {
                    m1 = prev;
                    n1 = root;
                }
                else{
                    m2 = root;
                }
            }
            prev = root;
            traversal(root->right, prev, m1, n1, m2);
        }
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode* m1 = NULL;
        TreeNode* n1 = NULL;
        TreeNode* m2 = NULL;
        TreeNode* prev = NULL;
        traversal(root, prev, m1, n1, m2);

        if(m2 == NULL){
            swap(m1->val, n1->val);
        }
        else{
            swap(m1->val, m2->val);
        }
    }
};