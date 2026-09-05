class Solution {
    int recursion(int i, int s, vector<int>& nums, int sum, int n, vector<vector<pair<int, int>>> &preCompute, vector<vector<int>>& dp){
        if(s > sum) return dp[i][sum+1] = 1e7;
        if(s == sum) return dp[i][s] = 0;
        if(i == n) return dp[i][s] = 1e7;

        if(dp[i][s] != -1) return dp[i][s];

        int skip = recursion(i+1, s, nums, sum, n, preCompute, dp);
        int noSkip = 1e7;
        for(auto it : preCompute[i]){
            noSkip = min(noSkip, it.second + recursion(i+1, s + it.first, nums, sum, n, preCompute, dp));
        }

        return dp[i][s] = min(skip, noSkip);
    }
public:
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<vector<pair<int, int>>> preCompute(n);
        for(int i=0;i<n;i++){
            int num = nums[i];
            vector<pair<int, int>> temp;
            int op = 0;
            while(num <= sum){
                temp.push_back({num, op});
                num = num * 2;
                op++;
            }

            op = 1;
            num = nums[i] / 2;
            while(num > 0){
                temp.push_back({num, op});
                num = num / 2;
                op++;
            }
            preCompute[i] = temp;
        }

        vector<vector<int>> dp(n+1, vector<int> (sum+2, -1));
        int ans = recursion(0, 0, nums, sum, n, preCompute, dp);
        if(ans == 1e7) return -1;
        return ans;
    }
};