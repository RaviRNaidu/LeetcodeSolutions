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
    TreeNode* construct(vector<int>& preorder, int start, int end){
        if(start > end) return NULL;
        TreeNode* root = new TreeNode(preorder[start]);
        if(start == end) return root;
        int idx = end + 1;
        for(int i=start+1;i<=end;i++){
            if(preorder[i] > preorder[start]){
                idx = i;
                break;
            }
        }
        root->left = construct(preorder, start+1, idx-1);
        root->right = construct(preorder, idx, end);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        return construct(preorder, 0, n-1);
    }
};