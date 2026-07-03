class Solution {
    int n;
    vector<vector<pair<int,int>>> adj;

    bool check(int mid, vector<bool>& online, long long k) {

        vector<long long> dist(n, LLONG_MAX);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[0] = 0;
        pq.push({0, 0});

        while(!pq.empty()){

            auto [cost, node] = pq.top();
            pq.pop();

            if(cost > dist[node]) continue;
            if(cost > k) continue;

            for(auto &[newNode, wt] : adj[node]){

                if(!online[newNode]) continue;
                if(wt < mid) continue;

                long long newCost = cost + wt;

                if(newCost < dist[newNode]){
                    dist[newNode] = newCost;
                    pq.push({newCost, newNode});
                }
            }
        }

        return dist[n-1] <= k;
    }

public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        n = online.size();
        adj.assign(n, {});

        vector<int> vals;

        for(auto &e : edges){

            int u = e[0];
            int v = e[1];
            int w = e[2];

            if(online[u]) {
                adj[u].push_back({v, w});
            }

            vals.push_back(w);
        }

        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int low = 0;
        int high = vals.size() - 1;
        int ans = -1;

        while(low <= high){

            int mid = (low + high) / 2;

            if(check(vals[mid], online, k)){
                ans = vals[mid];
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }
};