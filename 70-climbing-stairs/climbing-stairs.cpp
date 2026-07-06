class Solution {
    int climbing(int i, vector<int> &dp){
        if(i < 0) return 0;
        if(i == 0){
            return dp[i] = 1;
        }
        if(dp[i] != -1) return dp[i];
        return dp[i] = climbing(i-1, dp) + climbing(i-2, dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return climbing(n, dp);
    }
};