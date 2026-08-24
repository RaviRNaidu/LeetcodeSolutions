class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefix(n);
        prefix[0] = stones[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + stones[i];
        }
        vector<int> dp(n, 0);
        dp[n-2] = prefix[n-1];
        for(int i=n-3;i>=0;i--){
            dp[i] = max(dp[i+1], prefix[i+1] - dp[i+1]);
        }
        return dp[0];
    }
};