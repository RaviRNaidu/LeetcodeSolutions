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
    TreeNode* traversal(TreeNode* root){
        while(root->right != NULL){
            root = root->right;
        }
        return root;
    }
    bool isLeafNode(TreeNode* node){
        return (node->left == NULL && node->right == NULL);
    }
    TreeNode* remove(TreeNode* root){
        if(isLeafNode(root)) return NULL;
        //right not present
        if(root->right == NULL) return root->left;
        //left not present
        if(root->left == NULL) return root->right;

        TreeNode* rightChild = root->right;
        TreeNode* leftRight = traversal(root->left);
        leftRight->right = rightChild;
        return root->left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key) return remove(root);
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->val > key){
                if(curr->left != NULL && curr->left->val == key){
                    curr->left = remove(curr->left);
                    break;
                }
                else{
                    curr = curr->left;
                }
            }
            else{
                if(curr->right != NULL && curr->right->val == key){
                    curr->right = remove(curr->right);
                    break;
                }
                else{
                    curr = curr->right;
                }
            }
        }
        return root;
    }
};