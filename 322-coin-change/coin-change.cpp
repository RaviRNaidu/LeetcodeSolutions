class Solution {
    int recursion(int i, int amount, vector<int> &coins, vector<vector<int>> &dp){
        if(amount == 0) return dp[i][amount] = 0;
        if(i == 0) return dp[i][amount] = 1e9;

        if(dp[i][amount] != -1) return dp[i][amount];
        
        int notTake = recursion(i-1, amount, coins,dp);
        int take = 1e9;
        if(coins[i - 1] <= amount){
            take = 1 + recursion(i, amount - coins[i - 1], coins, dp);
        }

        return dp[i][amount] = min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, -1));
        int ans = recursion(n, amount, coins, dp);
        if(ans == 1e9) return -1;
        return ans;
    }
};