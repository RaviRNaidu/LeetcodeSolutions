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
    bool isLeafNode(TreeNode* node){
        return (node->left == NULL && node->right == NULL);
    }
    TreeNode* remove(TreeNode* root){
        if(isLeafNode(root)) return NULL;
        //right not present
        if(root->right == NULL) return root->left;
        //left not present
        if(root->left == NULL) return root->right;

        //iterating to the last node of left subTree
        TreeNode* temp = root->left;
        while(temp->right != NULL){
            temp = temp->right;
        }
        //link changes
        temp->right = root->right->left;
        root->right->left = root->left;
        return root->right;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key) return remove(root);
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};