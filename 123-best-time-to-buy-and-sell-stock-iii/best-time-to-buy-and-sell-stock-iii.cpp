class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> front(5, 0);
        front[1] = prices[n-1];
        front[3] = prices[n-1];
        for(int i=n-2;i>=0;i--){
            for(int cnt=3;cnt>=0;cnt--){
                int notTake = front[cnt];
                int take = 0;
                if(cnt % 2 == 0){
                    take = - prices[i] + front[cnt + 1];
                }
                else{
                    take = prices[i] + front[cnt + 1];
                }
                front[cnt] = max(notTake, take);
            }
        }
        return front[0];
    }
};