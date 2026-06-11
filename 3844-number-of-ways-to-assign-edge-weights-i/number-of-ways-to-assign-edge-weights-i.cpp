class Solution {
    int mod = 1e9 + 7;
    long long power(long long a, long long b){
        long long ans = 1;

        while(b){
            if(b & 1)
                ans = (ans * a) % mod;

            a = (a * a) % mod;
            b >>= 1;
        }

        return ans;
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adj[n+2];
        for(int i=0;i<n;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n+2, 0);
        int maxDepth = 0;
        queue<pair<int, int>> q;
        q.push({1, 0});
        vis[1] = 1;
        while(!q.empty()){
            int node = q.front().first;
            int dep = q.front().second;
            q.pop();

            maxDepth = max(maxDepth, dep);

            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it, dep + 1});
                }
            }
        }

        int ans = power(2, maxDepth - 1);
        return ans;
    }
};