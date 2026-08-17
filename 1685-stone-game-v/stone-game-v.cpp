class Solution {
    int recursion(int l, int r, vector<int>& stoneValue, vector<int>& preSum, vector<vector<int>> &dp){
        if(l == r) return dp[l][r] = 0;
        if(r - l == 1) return dp[l][r] = min(stoneValue[l-1], stoneValue[r-1]);

        if(dp[l][r] != -1) return dp[l][r];

        int ans = INT_MIN;
        for(int i=l;i<r;i++){
            int leftSum = preSum[i] - preSum[l-1];
            int rightSum = preSum[r] - preSum[i];
            int sum = 0;
            if(leftSum > rightSum){
                sum = rightSum + recursion(i+1, r, stoneValue, preSum, dp);
            }
            else if(leftSum < rightSum){
                sum = leftSum + recursion(l, i, stoneValue, preSum, dp);
            }
            else{
                sum = max(rightSum + recursion(i+1, r, stoneValue, preSum, dp), leftSum + recursion(l, i, stoneValue, preSum, dp));
            }
            ans = max(ans, sum);
        }

        return dp[l][r] = ans;
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> preSum(n+1, 0);
        for(int i=1;i<=n;i++){
            preSum[i] = preSum[i-1] + stoneValue[i-1];
        }

        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        int ans = recursion(1, n, stoneValue, preSum, dp);
        return ans;
    }
};