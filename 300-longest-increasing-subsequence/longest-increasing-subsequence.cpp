class Solution {
    int memoization(vector<int> &arr, int n){
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                int notTake = dp[i-1][j];
                int take = 0;
                if(j == n || arr[j] > arr[i - 1]){
                    take = 1 + dp[i-1][i-1];
                }
                dp[i][j] = max(notTake, take);
            }
        }
        return dp[n][n];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = memoization(nums, n);
        return ans;
    }
};