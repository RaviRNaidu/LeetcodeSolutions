class Solution {
    void helper(int num, int sum, unordered_map<int, int>& mpp, int op){
        num = num * 2;
        if(num == 0) return;
        while(num <= sum){
            if(mpp.find(num) != mpp.end()) mpp[num] = min(mpp[num], op);
            else mpp[num] = op;
            num = num * 2;
            op++;
        }
    }
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
            int num = nums[i] * 2;
            vector<pair<int, int>> temp;
            unordered_map<int, int> mpp;
            int op = 1;
            while(num <= sum){
                if(mpp.find(num) != mpp.end()) mpp[num] = min(mpp[num], op);
                else mpp[num] = op;
                num = num * 2;
                op++;
            }

            op = 0;
            num = nums[i];
            while(num > 0){
                if(mpp.find(num) != mpp.end()) mpp[num] = min(mpp[num], op);
                else mpp[num] = op;
                if(num % 2 != 0){
                    helper(num / 2, sum, mpp, op + 2);
                }
                num = num / 2;
                op++;
            }
            for(auto it : mpp){
                temp.push_back({it.first, it.second});
            }
            preCompute[i] = temp;
        }

        vector<vector<int>> dp(n+1, vector<int> (sum+2, -1));
        int ans = recursion(0, 0, nums, sum, n, preCompute, dp);
        if(ans == 1e7) return -1;
        return ans;
    }
};