class Solution {
    vector<vector<int>> bfs(vector<vector<int>>& grid, int drow[], int dcol[]){
        int n = grid.size();
        vector<vector<int>> dis(n, vector<int> (n, n));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    dis[i][j] = 0;
                    q.push({0, {i, j}});
                }
            }
        }

        while(!q.empty()){
            int dist = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                int newDist = dist + 1;
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && !grid[nrow][ncol] && dis[nrow][ncol] > newDist){
                    dis[nrow][ncol] = newDist;
                    q.push({newDist, {nrow, ncol}});
                }
            }
        }
        return dis;
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0;
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        
        vector<vector<int>> minDist = bfs(grid, drow, dcol);

        vector<vector<int>> dis(n, vector<int> (n, 0));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, less<pair<int, pair<int, int>>>> pq;
        int ini = minDist[0][0];
        if(!grid[0][0]){
            pq.push({ini, {0, 0}});
        }
        while(!pq.empty()){
            int dist = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(dist < dis[row][col]) continue;

            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && !grid[nrow][ncol]){
                    int nMinDistT = min(dist, minDist[nrow][ncol]);
                    if(nMinDistT > dis[nrow][ncol]){
                        dis[nrow][ncol] = nMinDistT;
                        pq.push({nMinDistT, {nrow, ncol}});
                    }
                }
            }
        }
        return dis[n-1][n-1];
    }
};