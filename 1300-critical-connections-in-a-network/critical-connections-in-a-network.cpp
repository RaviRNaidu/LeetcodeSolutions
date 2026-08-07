class Solution {
    void dfs(int node, int parent, vector<int> &minTime, vector<int> &tin, vector<int> adj[], int &cnt,      vector<vector<int>> &ans){
        minTime[node] = cnt;
        tin[node] = cnt;
        cnt++;

        for(auto it : adj[node]){
            if(it == parent) continue;
            if(!tin[it]){
                dfs(it, node, minTime, tin, adj, cnt, ans);
                minTime[node] = min(minTime[node], minTime[it]);
                if(tin[node] < minTime[it]){
                    ans.push_back({node, it});
                }
            }
            else{
                minTime[node] = min(minTime[node], tin[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> minTime(n, 0);
        vector<int> tin(n, 0);

        vector<vector<int>> ans;
        int cnt = 1;
        dfs(0, -1, minTime, tin, adj, cnt, ans);
        return ans;
    }
};