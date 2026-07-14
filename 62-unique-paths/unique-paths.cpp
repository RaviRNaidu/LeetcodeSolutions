class Solution {
    int recursion(int i, int j, vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0;
        if(i == 0 && j == 0) return dp[i][j] = 1;

        if(dp[i][j] != -1) return dp[i][j];

        int up = recursion(i-1, j, dp);
        int left = recursion(i, j-1, dp);
        return dp[i][j] = (up + left);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return recursion(m-1, n-1, dp);
    }
};