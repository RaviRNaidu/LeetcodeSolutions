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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        map<int,map<int, multiset<int>>> mpp;
        queue<pair<TreeNode*,pair<int, int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode* temp = q.front().first;
            int level = q.front().second.first;
            int index = q.front().second.second;
            q.pop();
            mpp[index][level].insert(temp->val);
            if(temp->left) q.push({temp->left,{level+1,index - 1}});
            if(temp->right) q.push({temp->right, {level + 1, index + 1}});
        }

        for(auto it : mpp){
            vector<int> col;
            for(auto i : it.second){
                col.insert(col.end(),i.second.begin(),i.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};