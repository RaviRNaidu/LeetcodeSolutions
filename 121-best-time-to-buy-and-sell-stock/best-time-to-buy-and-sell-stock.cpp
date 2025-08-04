class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int buy = prices[0];
        for(int i=0;i<n;i++){
            int cost = prices[i] - buy;
            profit = max(profit, cost);
            buy = min(buy, prices[i]);
        }
        return profit;
    }
};