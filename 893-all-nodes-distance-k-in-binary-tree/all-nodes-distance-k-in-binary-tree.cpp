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
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mpp;
        unordered_map<TreeNode*, bool> check;
        check[root] = false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp->left){
                mpp[temp->left] = temp;
                check[temp->left] = false;
                q.push(temp->left);
            }

            if(temp->right){
                mpp[temp->right] = temp;
                check[temp->right] = false;
                q.push(temp->right);
            }
        }

        vector<int> ans;
        queue<TreeNode*> n;
        n.push(target);
        check[target] = true;
        int i = 0;
        while(!n.empty() && i < k){
            int size = n.size();
            for(int j=0;j<size;j++){
                TreeNode* cur = n.front();
                n.pop();

                if(cur->left && check[cur->left] == false){
                    n.push(cur->left);
                    check[cur->left] = true;
                }
                if(cur->right && check[cur->right] == false){
                    n.push(cur->right);
                    check[cur->right] = true;
                }
                if(mpp.find(cur) != mpp.end() && check[mpp[cur]] == false){
                    n.push(mpp[cur]);
                    check[mpp[cur]] = true;
                }
            }
            i++;
        }

        while(!n.empty()){
            auto it = n.front();
            n.pop();

            ans.push_back(it->val);
        }
        return ans;
    }
};