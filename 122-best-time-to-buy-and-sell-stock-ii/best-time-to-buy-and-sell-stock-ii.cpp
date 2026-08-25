class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int frontTake = 0;
        int frontNotTake = prices[n-1];
        for(int i=n-2;i>=0;i--){
            int currNotTake = max(prices[i] + frontTake, frontNotTake);
            int currTake = max(frontTake, - prices[i] + frontNotTake);
            frontNotTake = currNotTake;
            frontTake = currTake;
        }
        return frontTake;
    }
};