class Solution {
    int recursion(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp){
        if(i == 0 || j == 0) return dp[i][j] = 0;
        if(i == 1 && j == 1 && !obstacleGrid[i-1][j-1]) return dp[i][j] = 1;
        if(obstacleGrid[i-1][j-1] == 1) return dp[i][j] = 0;

        if(dp[i][j] != -1) return dp[i][j];

        int left = recursion(i, j-1, obstacleGrid, dp);
        int up = recursion(i-1, j, obstacleGrid, dp);

        return dp[i][j] = left + up;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return recursion(n, m, obstacleGrid, dp);
    }
};