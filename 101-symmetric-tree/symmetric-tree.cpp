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
    bool solution(TreeNode* leftTree, TreeNode* rightTree){
        if(leftTree == NULL || rightTree == NULL){
            return (leftTree == rightTree);
        }
        
        if(leftTree->val != rightTree->val){
            return false;
        }
        
        return (solution(leftTree->left, rightTree->right) && 
               solution(leftTree->right,rightTree->left));
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return solution(root->left, root->right);
    }
};