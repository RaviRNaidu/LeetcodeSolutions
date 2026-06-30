class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        int n = grid.size();
        vector<vector<int>> dis(n, vector<int> (n,1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        dis[0][0] = grid[0][0];
        while(!pq.empty()){
            int elevation = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && dis[nrow][ncol] > max(elevation, grid[nrow][ncol])){
                    dis[nrow][ncol] = max(elevation, grid[nrow][ncol]);
                    pq.push({dis[nrow][ncol], {nrow, ncol}});
                }
            }
        }
        return dis[n-1][n-1];
    }
};