class Solution {
    void dfs(int node, vector<int> adj[], vector<int> &vis){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m < n-1) return -1;
        vector<int> adj[n];
        for(int i=0;i<m;i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int compo = 0;
        vector<int> vis(n, 0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                compo++;
            }
        }
        return compo - 1;
    }
};