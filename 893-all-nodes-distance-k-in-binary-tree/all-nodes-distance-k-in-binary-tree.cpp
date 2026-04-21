/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*,TreeNode*> markParent(TreeNode* root){
        queue<TreeNode*> q;
        unordered_map<TreeNode*,TreeNode*> mpp;
        if(root == NULL) return mpp;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left){
                    mpp[temp->left] = temp;
                    q.push(temp->left);
                }
                if(temp->right){
                    mpp[temp->right] = temp;
                    q.push(temp->right);
                }
            }
        }
        return mpp;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*, TreeNode*> mpp = markParent(root);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int dist = 0;
        while(!q.empty()){
            int n = q.size();
            if(dist == k) break;
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left && !visited[temp->left]){
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                if(temp->right && !visited[temp->right]){
                    q.push(temp->right);
                    visited[temp->right] = true;
                }
                if(mpp.count(temp) && !visited[mpp[temp]]){
                    q.push(mpp[temp]);
                    visited[mpp[temp]] = true;
                }
            }
            dist++;
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};