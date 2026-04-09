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
            int min = q.front().second;
            int first, last;
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front().first;
                int curr_Idx = q.front().second - min;
                q.pop();
                if(i == 0) first = curr_Idx;
                if(i == n-1) last = curr_Idx;
                if(temp->left) q.push({temp->left,(2LL * curr_Idx) + 1});
                if(temp->right) q.push({temp->right,(2LL * curr_Idx) + 2});
            }
            maxWidth = max(maxWidth,(last - first) + 1);
        }
        return maxWidth;
    }
};