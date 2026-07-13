class Solution {
    int solution(vector<int>& nums, int n){
        vector<int> dp(n+1, 0);
        dp[1] = nums[0];
        for(int i=2;i<=n;i++){
            int pick = nums[i-1] + dp[i-2];
            int notPick = dp[i-1];

            dp[i] = max(pick, notPick);
        }
        return dp[n];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> temp;
        for(int i=1;i<n;i++){
            temp.push_back(nums[i]);
        }
        return max(solution(nums, n-1), solution(temp, n-1));
    }
};