class Solution {
    int recursion(int i, int take, vector<int>& prices, int n, vector<vector<int>> &dp){
        if(i == n-1){
            if(!take) return dp[i][take] = prices[n-1];
            else return dp[i][take] = 0;
        }

        if(dp[i][take] != -1) return dp[i][take];

        int notBuy = recursion(i+1, take, prices, n, dp);
        int buy = 0;
        if(take){
            buy = - prices[i] + recursion(i+1, !take, prices, n, dp);
        }
        else if(!take){
            buy = prices[i] + recursion(i+1, !take, prices, n, dp);
        }

        return dp[i][take] = max(notBuy, buy);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return recursion(0, true, prices, n, dp);
    }
};