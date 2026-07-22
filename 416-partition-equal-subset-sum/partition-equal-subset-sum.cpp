class Solution {
    int recursion(int i, int sum, vector<int> &nums, vector<vector<int>> &dp){
        if(sum == 0) return dp[i][sum] = 1;
        if(i == 0 && sum != 0) return dp[i][sum] = 0;

        if(dp[i][sum] != -1) return dp[i][sum];

        int take = 0;
        int notTake = recursion(i-1, sum, nums, dp);
        if(nums[i-1] <= sum){
            take = recursion(i-1, sum - nums[i-1], nums, dp);
        }

        return dp[i][sum] = take || notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum % 2 != 0) return false;
        vector<vector<int>> dp(n+1, vector<int> ((sum/2)+1, -1));
        if(recursion(n, sum/2, nums, dp)){
            return true;
        }
        return false;
    }
};