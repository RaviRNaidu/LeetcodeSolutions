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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode* root = NULL;
        unordered_map<int, pair<TreeNode*, TreeNode*>> mpp;
        for(auto &it : descriptions){
            int par = it[0];
            int chi = it[1];
            int isLeft = it[2];

            TreeNode* p = NULL;
            TreeNode* c = NULL;

            if(mpp.find(par) == mpp.end()){
                p = new TreeNode(par);
                if(root == NULL) root = p;
                mpp[par] = {p,NULL};
            }
            else{
                p = mpp[par].first;
            }

            if(mpp.find(chi) == mpp.end()){
                c = new TreeNode(chi);
                mpp[chi] = {c,p};
            }
            else {
                c = mpp[chi].first;
            }

            if(isLeft) p->left = c;
            else p->right = c;

            if(mpp[chi].second == NULL) mpp[chi] = {c,p};
        }

        for(auto &it : mpp){
            if(it.second.second == NULL){
                root = it.second.first;
            }
        }
        return root;
    }
};