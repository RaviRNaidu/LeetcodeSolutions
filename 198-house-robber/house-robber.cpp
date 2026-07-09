class Solution {
    int recursion(int i, vector<int> &nums, vector<int> &dp){
        if(i == 0) return dp[i] = 0;
        if(i == 1) return dp[i] = nums[i-1];

        if(dp[i] != -1) return dp[i];

        int take = nums[i-1] + recursion(i-2, nums, dp);
        int notTake = recursion(i-1, nums, dp);

        return dp[i] = max(take, notTake);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return recursion(n, nums, dp);
    }
};