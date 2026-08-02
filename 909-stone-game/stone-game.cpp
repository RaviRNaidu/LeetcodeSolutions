class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> dp(n, 0);

        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i == j){
                    dp[j] = piles[i];
                }
                else{
                    int left = piles[i] - dp[j];
                    int right = piles[j] - dp[j-1];

                    dp[j] = max(left, right);
                }
            }
        }

        int ans = dp[n-1];
        if(ans > 0) return true;
        return false;
    }
};