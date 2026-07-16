class Solution {
    int recursion(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i == 0 || j == 0) return dp[i][j] = 1e7;
        if(i == 1 && j == 1) return dp[i][j] = grid[i-1][j-1];

        if(dp[i][j] != -1) return dp[i][j];

        int up = grid[i-1][j-1] + recursion(i-1, j, grid, dp);
        int left = grid[i-1][j-1] + recursion(i, j-1, grid, dp);

        return dp[i][j] = min(up, left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
        return recursion(n, m, grid, dp);
    }
};