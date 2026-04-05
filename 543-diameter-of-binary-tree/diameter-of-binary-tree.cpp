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
    private:
    int solution = 0;

    public:
    int recursion(TreeNode* root, int& diameter){
        if(root == NULL) return 0;
        int lh = recursion(root->left, diameter);
        int rh = recursion(root->right, diameter);
        diameter = max(diameter, lh + rh);
        return max(lh, rh) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int diameter = 0;

        recursion(root, diameter);
        return diameter;
    }
};