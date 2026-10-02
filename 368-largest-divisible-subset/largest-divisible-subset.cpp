class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n);
        int lastIdx = 0;
        int maxi = 1;
        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int j=0;j<i;j++){
                if((nums[j] % nums[i] == 0 || nums[i] % nums[j] == 0) && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(maxi < dp[i]){
                lastIdx = i;
                maxi = dp[i];
            }
        }

        vector<int> ans;
        ans.push_back(nums[lastIdx]);
        while(hash[lastIdx] != lastIdx){
            ans.push_back(nums[hash[lastIdx]]);
            lastIdx = hash[lastIdx];
        }
        return ans;
    }
};