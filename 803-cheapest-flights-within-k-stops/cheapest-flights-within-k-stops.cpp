class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights.size();
        vector<pair<int,int>> adj[n];
        for(int i=0;i<m;i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int c = flights[i][2];

            adj[u].push_back({v, c});
        }

        vector<int> distance(n, 1e9);
        distance[src] = 0;

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0, {src, 0}});
        while(!pq.empty()){
            int stops = pq.top().first;
            int node = pq.top().second.first;
            int price = pq.top().second.second;
            pq.pop();

            for(auto it : adj[node]){
                int newPrice = price + it.second;
                if(newPrice < distance[it.first] && stops + 1 <= k+1){
                    distance[it.first] = newPrice;
                    pq.push({stops + 1, {it.first, newPrice}});
                }
            }
        }

        if(distance[dst] == 1e9) return -1;
        return distance[dst];
    }
};