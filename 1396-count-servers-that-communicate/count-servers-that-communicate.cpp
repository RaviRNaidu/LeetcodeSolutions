class Solution {
    void finding(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis, int n, int m, int& cnt){
        for(int row=0;row<n;row++){
            if(row != i && grid[row][j] && !vis[row][j]){
                vis[row][j] = true;
                cnt++;
                if(!vis[i][j]){
                    vis[i][j] = true;
                    cnt++;
                }
                finding(row, j, grid, vis, n, m, cnt);
            }
        }

        for(int col=0;col<m;col++){
            if(col != j && grid[i][col] && !vis[i][col]){
                vis[i][col] = true;
                cnt++;
                if(!vis[i][j]){
                    vis[i][j] = true;
                    cnt++;
                }
                finding(i, col, grid, vis, n, m, cnt);
            }
        }
    }
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !vis[i][j]) finding(i, j, grid, vis, n, m, cnt);
            }
        }
        return cnt;
    }
};