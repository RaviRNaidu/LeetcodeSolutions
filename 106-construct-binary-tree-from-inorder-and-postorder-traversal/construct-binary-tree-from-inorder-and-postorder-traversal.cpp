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
    TreeNode* constructTree(vector<int> &postorder, int postSt, int postEnd, vector<int> &inorder, int inSt, int inEnd, unordered_map<int, int> &mpp){
        if(postSt > postEnd || inSt > inEnd){
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int index = mpp[postorder[postEnd]];
        int nodeRight = inEnd - index;
        root->left = constructTree(postorder, postSt, postEnd - nodeRight - 1, inorder, inSt, index - 1, mpp);
        root->right = constructTree(postorder, postEnd - nodeRight, postEnd - 1, inorder, index + 1, inEnd, mpp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mpp;
        int n = inorder.size();
        for(int i=0;i<n;i++){
            mpp[inorder[i]] = i;
        }

        TreeNode* root = constructTree(postorder, 0, n-1, inorder, 0, n-1, mpp);
        return root;
    }
};