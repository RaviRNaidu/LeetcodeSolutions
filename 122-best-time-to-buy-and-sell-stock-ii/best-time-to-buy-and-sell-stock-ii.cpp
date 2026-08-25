class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> front(2, 0);
        front[0] = prices[n-1];

        for(int i=n-2;i>=0;i--){
            vector<int> curr(2, 0);
            for(int take=0;take<2;take++){
                int notBuy = front[take];
                int buy = 0;
                if(take){
                    buy = - prices[i] + front[!take];
                }
                else if(!take){
                    buy = prices[i] + front[!take];
                }

                curr[take] = max(notBuy, buy);
            }
            front = curr;
        }
        return front[1];
    }
};