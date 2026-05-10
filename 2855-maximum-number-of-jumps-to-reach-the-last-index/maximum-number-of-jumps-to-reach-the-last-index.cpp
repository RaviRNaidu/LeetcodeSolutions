class Solution {
    int recursion(int index, int target, vector<int> &nums, vector<int> &dp){
        if(index == 0){
            return dp[index] = 0;
        }

        if(dp[index] != -1) return dp[index];

        int ans = -1;
        for(int i=0;i<index;i++){
            int diff = nums[index] - nums[i];
            if(diff >= -target && diff <= target){
                if(recursion(i, target, nums, dp) >= 0){
                    ans = max(ans, 1 + recursion(i, target, nums, dp));
                }
            }
        }

        return dp[index] = ans;
    }
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        
        dp[0] = 0;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = nums[i] - nums[j];
                if(diff >= -target && diff <= target){
                    if(dp[j] >= 0){
                        dp[i] = max(dp[i], 1 + dp[j]);
                    }
                }
            }
        }

        return dp[n-1];
    }
};