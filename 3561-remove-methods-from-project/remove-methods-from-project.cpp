class Solution {
    void dfs(int node, vector<int> adj[], vector<int> &vis, int &cnt){
        vis[node] = 1;
        cnt++;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, cnt);
            }
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> adj[n];
        for(auto it : invocations){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        vector<int> vis(n, 0);
        int cnt = 0;
        dfs(k, adj, vis, cnt);
        if(cnt == n) return {};
        
        bool flag = false;
        for(auto it : invocations){
            int u = it[0];
            int v = it[1];
            if(!vis[u] && vis[v]){
                flag = true;
                break;
            }
        }

        if(flag){
            vector<int> ans;
            for(int i=0;i<n;i++){
                ans.push_back(i);
            }
            return ans;
        }
        else{
            vector<int> ans;
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    ans.push_back(i);
                }
            }
            return ans;
        }
    }
};