class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> front(2, 0);
        front[0] = prices[n-1] - fee;
        for(int i=n-2;i>=0;i--){
            vector<int> curr(2, 0);
            for(int buy=0;buy<2;buy++){
                int skip = front[buy];
                int noSkip = 0;
                if(buy){
                    noSkip = -prices[i] + front[!buy];
                }
                else{
                    noSkip = prices[i] - fee + front[!buy];
                }
                curr[buy] = max(skip, noSkip);
            }
            front = curr;
        }
        return front[1];
    }
};