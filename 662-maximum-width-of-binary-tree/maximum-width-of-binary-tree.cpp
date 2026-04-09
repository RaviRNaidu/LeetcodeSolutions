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
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int maxWidth = INT_MIN;
        while(!q.empty()){
            int n = q.size();
            maxWidth = max(maxWidth,(q.back().second - q.front().second) + 1);
            for(int i=0;i<n;i++){
                auto temp = q.front();
                q.pop();

                if(temp.first->left) q.push({temp.first->left,(2LL * temp.second) + 1});
                if(temp.first->right) q.push({temp.first->right,(2LL * temp.second) + 2});
            }
        }
        return maxWidth;
    }
};