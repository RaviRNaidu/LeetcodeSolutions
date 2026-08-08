class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned long long> prev(amount+1, 0);
        prev[0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                unsigned long long notTake = prev[j];
                unsigned long long take = 0;
                if(coins[i-1] <= j){
                    take = prev[j - coins[i-1]];
                }
                prev[j] = notTake + take;
            }
        }
        return (int)prev[amount];
    }
};