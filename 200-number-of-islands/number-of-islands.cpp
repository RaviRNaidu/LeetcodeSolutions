class Solution {
    void dfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& vis, int drow[], int dcol[], int n, int m) {
        vis[row][col] = 1;
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                dfs(nrow, ncol, grid, vis, drow, dcol, n, m);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    cnt++;
                    dfs(i, j, grid, vis, drow, dcol, n, m);
                }
            }
        }

        return cnt;
    }
};