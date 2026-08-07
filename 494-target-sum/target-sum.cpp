class Solution {
    int recursion(int i, vector<int> &nums, int target, vector<vector<int>> &dp){
        if(i == 0){
            if(target == 0 && nums[i] == 0) return dp[i][target] = 2;
            if(target == nums[i] || target == 0) return dp[i][target] = 1;
            return dp[i][target] = 0;
        }

        int notTake = recursion(i-1, nums, target, dp);
        int take = 0;
        if(nums[i] <= target){
            take = recursion(i-1, nums, target - nums[i], dp);
        }

        return dp[i][target] = notTake + take;
    }
public:
    int findTargetSumWays(vector<int>& nums, int d) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum - d < 0 || ((sum - d) % 2)) return 0;
        int target = (sum - d) / 2;
        vector<vector<int>> dp(n, vector<int> (target+1, -1));
        int ans = recursion(n-1, nums, target, dp);
        return ans;
    }
};