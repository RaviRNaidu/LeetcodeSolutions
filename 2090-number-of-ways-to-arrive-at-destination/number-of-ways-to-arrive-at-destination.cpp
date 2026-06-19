class Solution {
    int mod = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int m = roads.size();
        vector<pair<int, int>> adj[n];
        for(int i=0;i<m;i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int t = roads[i][2];

            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        vector<long long> dis(n, LLONG_MAX);
        vector<long long> path(n,0);
        dis[0] = 0;
        path[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            long long time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(time > dis[node]) continue;

            for(auto it : adj[node]){
                int newNode = it.first;
                long long newTime = time + it.second;
                if(newTime < dis[newNode]){
                    path[newNode] = path[node];
                    dis[newNode] = newTime;
                    pq.push({newTime, newNode});
                }
                else if(newTime == dis[newNode]){
                    path[newNode] = (path[newNode] + path[node]) % mod;
                }
            }
        }
        return path[n-1] % mod;
    }
};