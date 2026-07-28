class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int> prev(amount+1, 1e9);
        prev[0] = 0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                int notTake = prev[j];
                int take = 1e9;
                if(coins[i - 1] <= j){
                    take = 1 + prev[j - coins[i - 1]];
                }
                prev[j] = min(take, notTake);
            }
        }

        int ans = prev[amount];
        if(ans == 1e9) return -1;
        return ans;
    }
};