class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> Fprev(2, 0);
        vector<int> Sprev(2, 0);
        Sprev[0] = prices[n-1];

        for(int i=n-2;i>=0;i--){
            vector<int> curr(2, 0);
            for(int buy=1;buy>=0;buy--){
                int skip = Sprev[buy];
                int noSkip = 0;
                if(buy){
                    noSkip = -prices[i] + Sprev[!buy];;
                }
                else{
                    noSkip = prices[i] + Fprev[!buy];;
                }
                curr[buy] = max(skip, noSkip);
            }
            Fprev = Sprev;
            Sprev = curr;
        }
        return Sprev[1];
    }
};