class Solution {
    void dfs(int node, vector<pair<int, int>> adj[], vector<int> &vis, int &ans){
        vis[node] = 1;
        for(auto it : adj[node]){
            int newNode = it.first;
            int dis = it.second;
            ans = min(ans, dis);
            if(!vis[newNode]){
                dfs(newNode, adj, vis, ans);
            }
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> vis(n+1, 0);
        vector<pair<int, int>> adj[n+1];
        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int d = it[2];
            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }
        int ans = INT_MAX;
        dfs(1, adj, vis, ans);
        return ans;
    }
};