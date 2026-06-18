class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m = times.size();
        vector<pair<int, int>> adj[n+1];
        vector<int> vis(n+1, 1e9);
        for(int i=0;i<m;i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});
        vis[k] = 0;
        while(!pq.empty()){
            int t = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                int newTime = t + it.second;
                int nNode = it.first;
                if(newTime < vis[nNode]){
                    vis[nNode] = newTime;
                    pq.push({newTime, nNode});
                }
            }
        }

        int ans = INT_MIN;
        for(int i=1;i<=n;i++){
            ans = max(ans, vis[i]);
        }

        if(ans == 1e9) return -1;
        return ans;
    }
};