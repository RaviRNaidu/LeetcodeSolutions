class Solution {
    int recursion(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        if (i == j) return dp[i][j] = nums[i];

        if(dp[i][j] != -1) return dp[i][j];
    
        int pickLeft  = nums[i] - recursion(i + 1, j, nums, dp);
        int pickRight = nums[j] - recursion(i, j - 1, nums, dp);
        
        return dp[i][j] = max(pickLeft, pickRight);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        int sum = recursion(0, n-1, nums, dp);
        if(sum >= 0) return true;
        return false;
    }
};