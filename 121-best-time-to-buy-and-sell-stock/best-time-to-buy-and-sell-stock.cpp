class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> sum(n);
        sum[n-1] = prices[n-1];
        for(int i=n-2;i>=0;i--){
            sum[i] = max(prices[i], sum[i+1]);
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, sum[i] - prices[i]);
        }

        return ans;
    }
};