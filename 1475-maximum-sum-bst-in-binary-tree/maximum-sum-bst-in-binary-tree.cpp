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
    pair<int, pair<int, int>> recursion(TreeNode* root, int &ans){
        if(root == NULL) return {0, {INT_MAX, INT_MIN}};

        auto l = recursion(root->left, ans);
        auto r = recursion(root->right, ans);
        
        int leftMax = l.second.second;
        int rightMin = r.second.first;
        
        if(root->val > leftMax && root->val < rightMin){

            int sum = l.first + r.first + root->val;
            
            ans = max(sum, ans);

            int mini = min(l.second.first, root->val);
            int maxi = max(r.second.second, root->val);

            return{sum , {mini, maxi}};
        }
        return {INT_MIN, {INT_MIN, INT_MAX}};
    }
public:
    int maxSumBST(TreeNode* root) {
        int maxi = -1e9;
        recursion(root, maxi);
        if(maxi < 0) return 0;
        return maxi;
    }
};