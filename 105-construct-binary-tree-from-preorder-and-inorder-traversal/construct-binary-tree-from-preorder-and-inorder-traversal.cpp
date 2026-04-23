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
    TreeNode* creatingTree(vector<int> &preOrder,int preSt,int preEnd, vector<int> &inOrder, 
                    int inSt, int inEnd, unordered_map<int, int> &mpp){
        if(preSt > preEnd || inSt > inEnd) return NULL;
        
        TreeNode* root = new TreeNode(preOrder[preSt]);
        int inIndx = mpp[preOrder[preSt]];
        int numLeft = inIndx - inSt;

        root->left = creatingTree(preOrder,preSt + 1,preSt + numLeft,inOrder,inSt,inIndx - 1,mpp);
        root->right = creatingTree(preOrder,preSt + numLeft + 1,preEnd, inOrder, inIndx + 1, inEnd,mpp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[inorder[i]] = i;
        }

        return creatingTree(preorder, 0, n-1, inorder,0, n-1 ,mpp);
    }
};