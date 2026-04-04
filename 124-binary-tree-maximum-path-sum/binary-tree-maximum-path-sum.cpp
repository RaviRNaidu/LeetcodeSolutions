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
    int recursion(TreeNode* root, int& maxi){
        if(root == NULL) return 0;
        int ls = max(0,recursion(root->left, maxi));
        int rs = max(0,recursion(root->right, maxi));
        int sum = ls + rs + root->val;
        maxi = max(maxi, sum);
        return max(ls,rs) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        int max = INT_MIN;
        int sum = recursion(root,max);
        return max;
    }
};