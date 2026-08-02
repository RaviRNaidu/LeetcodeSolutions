class Solution {
    int recursion(int i, int j, vector<int>& piles, vector<vector<int>> &dp){
        if(i == j) return dp[i][j] = piles[i];

        if(dp[i][j] != -1) return dp[i][j];

        int left = piles[i] - recursion(i+1, j, piles, dp);
        int right = piles[j] - recursion(i, j-1, piles, dp);

        return dp[i][j] = max(left, right);
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        int ans = recursion(0, n-1, piles, dp);
        if(ans > 0) return true;
        return false;
    }
};