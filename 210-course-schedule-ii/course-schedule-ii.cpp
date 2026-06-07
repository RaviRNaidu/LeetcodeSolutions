class Solution {
    bool dfs(int node, vector<bool> &vis, vector<int> adj[], stack<int> &st, vector<int> &path){
        vis[node] = true;
        path[node] = 1;
        for(auto it : adj[node]){
            if(vis[it] && path[it]){
                return false;
            }
            else if(!vis[it]){
                if(dfs(it, vis, adj, st, path) == false) return false;
            }
        }
        path[node] = 0;
        st.push(node);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto it : prerequisites){
            int u = it[1];
            int v = it[0];
            adj[u].push_back(v);
        }

        vector<bool> vis(numCourses, false);
        vector<int> path(numCourses, 0);
        stack<int> st;
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i, vis, adj, st, path) == false) return ans;
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};