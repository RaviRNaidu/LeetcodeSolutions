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
    void traversal(TreeNode* root, int & cnt){
        if(root != NULL){
            traversal(root->left, cnt);
            cnt++;
            traversal(root->right, cnt);
        }
    }
public:
    int countNodes(TreeNode* root) {
        int cnt = 0;
        traversal(root, cnt);
        return cnt;
    }
};