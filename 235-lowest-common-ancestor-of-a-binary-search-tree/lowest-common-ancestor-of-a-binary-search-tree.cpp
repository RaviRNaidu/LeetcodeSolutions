/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* finding(TreeNode* root, TreeNode* p, TreeNode* q){
        while(true){
            if(root->val > p->val && root->val > q->val){
                root = root->left;
            }
            else if(root->val < p->val && root->val < q->val){
                root = root->right;
            }
            else{
                return root;
            }
        }
        return NULL;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* LCA = finding(root, p, q);
        return LCA;
    }
};