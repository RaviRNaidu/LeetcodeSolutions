class Solution {
    int recursion(int idx, vector<int> &piles, int m, vector<int> &suffix, int n, vector<vector<int>>& dp){
        if(idx == n) return dp[idx][m] = 0;

        if(dp[idx][m] != -1) return dp[idx][m];

        int allow = 2 * m;
        int ans = INT_MIN;
        for(int i=1;i<=allow;i++){
            if(idx + i <= n){
                ans = max(ans, (suffix[idx] - suffix[idx + i]) - recursion(idx + i, piles, max(i, m), suffix, n, dp));
            }
            else{
                break;
            }
        }
        if(ans == INT_MIN) return dp[idx][m] = 0;
        return dp[idx][m] = ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffix(n+1, 0);
        for(int i=n-1;i>=0;i--){
            suffix[i] = piles[i] + suffix[i+1];
        }
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        for(int idx=n-1;idx>=0;idx--){
            for(int m=n;m>=1;m--){
                int allow = 2 * m;
                int ans = INT_MIN;
                for(int i=1;i<=allow;i++){
                    if(idx + i <= n){
                        ans = max(ans, (suffix[idx] - suffix[idx + i]) - dp[idx + i][max(i, m)]);
                    }
                    else{
                        break;
                    }
                }
                if(ans == INT_MIN) dp[idx][m] = 0;
                dp[idx][m] = ans;
            }
        }
        int ans = dp[0][1];
        ans = (suffix[0] + ans) / 2;
        return ans;
    }
};