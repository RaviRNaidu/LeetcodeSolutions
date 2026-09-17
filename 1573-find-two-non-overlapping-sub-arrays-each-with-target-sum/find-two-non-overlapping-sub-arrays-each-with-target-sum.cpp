class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp(n, INT_MAX);
        int ans = INT_MAX;
        int min_len = INT_MAX;
        int l = 0;
        int sum = 0;
        for(int r=0;r<n;r++){
            sum += arr[r];
            while(l < r && sum > target){
                sum -= arr[l];
                l++;
            }
            if(sum == target){
                int len = r - l + 1;
                if(l > 0 && dp[l-1] != INT_MAX){
                    ans = min(ans, len + dp[l-1]);
                }
                min_len = min(min_len, len);
            }
            dp[r] = min_len;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};