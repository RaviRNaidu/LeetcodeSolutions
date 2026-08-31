class Solution {
    int recursion(int i, int buy, vector<int>& prices, int n, vector<vector<int>> &dp){
        if(i == n) return dp[i][buy] = 0;
        if(i == n-1){
            if(!buy) return dp[i][buy] = prices[n-1];
            return dp[i][buy] = 0;
        }

        if(dp[i][buy] != -1) return dp[i][buy];

        int skip = recursion(i+1, buy, prices, n, dp);
        int noSkip = 0;
        if(buy){
            noSkip = -prices[i] + recursion(i+1, !buy, prices, n, dp);
        }
        else{
            noSkip = prices[i] + recursion(i+2, !buy, prices, n, dp);
        }

        return dp[i][buy] = max(skip, noSkip);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, -1));
        return recursion(0, 1, prices, n, dp);
    }
};