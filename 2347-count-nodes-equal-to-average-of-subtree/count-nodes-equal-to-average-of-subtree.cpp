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
    pair<int, int> solution(TreeNode* root, int& ans){
        if(root == NULL) return {0,0};

        auto left = solution(root->left, ans);
        auto right = solution(root->right, ans);

        int sum = left.first + right.first + root->val;
        int cnt = left.second + right.second + 1;
        if(sum / cnt == root->val) ans++;

        return {sum, cnt};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solution(root, ans);
        return ans;
    }
};