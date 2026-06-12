class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

        vector<vector<int>> vis(n, vector<int> (m, 1e9));
        vis[0][0] = 1;

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({1, {0,0}});
        while(!pq.empty()){
            int dis = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(dis > vis[row][col]) continue;

            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(i == 0 && j == 0) continue;
                    int nrow = row + i;
                    int ncol = col + j;
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0){
                        if(vis[nrow][ncol] > dis + 1){
                            vis[nrow][ncol] = dis + 1;
                            pq.push({dis + 1, {nrow, ncol}});
                        }
                    }
                }
            }
        }

        if(vis[n-1][m-1] == 1e9) return -1;
        return vis[n-1][m-1];
    }
};