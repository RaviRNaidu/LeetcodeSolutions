class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int m = 2 * k;
        vector<int> front(m+1, 0);
        for(int i=0;i<=m;i++){
            if(i % 2 != 0) front[i] = prices[n-1];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int notBuy = front[j];
                int buy = 0;
                if(j % 2 == 0){
                    buy = - prices[i] + front[j+1];
                }
                else{
                    buy = prices[i] + front[j+1];
                }
                front[j] = max(notBuy, buy);
            }
        }
        return front[0];
    }
};