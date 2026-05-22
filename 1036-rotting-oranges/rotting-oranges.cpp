class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));

        queue<pair<int, pair<int, int>>> q;
        
        int frestOranges = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({0 , {i, j}});
                    vis[i][j] = 1;
                }
                else if(grid[i][j] == 1){
                    frestOranges++;
                }
            }
        }

        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0 ,-1};

        int rottenOranges = 0;

        int timer = 0;
        while(!q.empty()){
            int row = q.front().second.first;
            int col = q.front().second.second;
            int time = q.front().first;
            timer = max(timer, time);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    rottenOranges++;
                    q.push({time + 1,{nrow, ncol}});
                }
            }
        }

        if(rottenOranges != frestOranges) return -1;

        return timer;
    }
};