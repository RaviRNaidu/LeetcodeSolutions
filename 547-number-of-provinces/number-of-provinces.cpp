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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<int> adj[n];
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        for(int i=0;i<n;i++){
            for(auto it : adj[i]){
                if(!vis[it]){
                    dfs(it, adj, vis);
                    cnt++;
                }
            }
        }
    
        return cnt;
    }
};