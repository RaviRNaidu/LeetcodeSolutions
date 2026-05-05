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
    void finding(TreeNode* root, vector<int> &arr){
        if(root != NULL){
            finding(root->left, arr);
            arr.push_back(root->val);
            finding(root->right, arr);
        }
        return;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        finding(root, arr);
        return arr[k-1];
    }
};