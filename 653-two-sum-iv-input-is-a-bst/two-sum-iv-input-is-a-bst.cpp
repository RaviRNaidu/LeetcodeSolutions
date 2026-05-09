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
    void traversal(TreeNode* root, vector<int> &arr){
        if(root != NULL){
            traversal(root->left, arr);
            arr.push_back(root->val);
            traversal(root->right, arr);
        }
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        traversal(root, arr);
        int n = arr.size();
        int i = 0;
        int j = n-1;
        while(i < j){
            if(arr[i] + arr[j] == k){
                return true;
            }
            if(arr[i] + arr[j] > k){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};