class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        vector<int> dp(n, 1);

        int maxLen = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        maxLen = max(maxLen, dp[i]);
                        ans[i] = ans[j];
                    }
                    else if(dp[j] + 1 == dp[i]){
                        ans[i] += ans[j];
                    }
                }
            }
        }
        
        int sol = 0;
        for(int i=0;i<n;i++){
            if(maxLen == dp[i]){
                sol += ans[i];
            }
        }

        return sol;
    }
};