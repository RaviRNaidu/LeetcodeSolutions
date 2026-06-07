class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> inDeg(numCourses,0);
        for(auto it : prerequisites){
            int u = it[1];
            int v = it[0];
            adj[u].push_back(v);
            inDeg[v] += 1;
        }

        vector<bool> vis(numCourses, false);
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(!vis[i] && inDeg[i] == 0){
                q.push(i);
                vis[i] = true;
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it : adj[node]){
                inDeg[it]--;
                if(inDeg[it] == 0){
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
        if(ans.size() != numCourses) return {};
        else return ans;
    }
};