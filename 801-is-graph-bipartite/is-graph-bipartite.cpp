class Solution {
    bool dfs(int node, int parent, vector<vector<int>> &graph, vector<int> &vis){
        vis[node] = !parent;
        bool ans = true;
        for(auto it : graph[node]){
            if(vis[it] == vis[node]){
                return false;
            }
            else if(vis[it] == -1){
                ans = ans && dfs(it, vis[node], graph, vis);
            }
        }
        return ans;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i] == -1){
                bool ans = dfs(i,0, graph, vis);
                if(!ans) return ans;
            }
        }
        return true;
    }
};