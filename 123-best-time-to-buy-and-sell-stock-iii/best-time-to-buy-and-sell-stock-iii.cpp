class Solution {
    int recursion(int i, bool buy, int cnt, vector<int>& prices, int n, vector<vector<vector<int>>> &dp){
        if(cnt == 2) return dp[i][buy][cnt] = 0;
        if(i == n-1){
            if(!buy) return dp[i][buy][cnt] = prices[n-1];
            else return dp[i][buy][cnt] = 0;
        }

        if(dp[i][buy][cnt] != -1) return dp[i][buy][cnt];

        int notTake = recursion(i+1, buy, cnt, prices, n, dp);
        int take = 0;
        if(buy){
            take = - prices[i] + recursion(i+1, !buy, cnt, prices, n, dp);
        }
        else take = prices[i] + recursion(i+1, !buy, cnt + 1, prices, n, dp);

        return dp[i][buy][cnt] = max(notTake, take);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
        return recursion(0, true, 0, prices, n, dp);
    }
};