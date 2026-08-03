class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n+1, INT_MIN);
        dp[n-1] = stoneValue[n-1];
        dp[n] = 0;

        for(int i=n-2;i>=0;i--){
            int one = stoneValue[i] - dp[i+1];
            int two = INT_MIN, three = INT_MIN;
            if(i < n-1){
                two = (stoneValue[i] + stoneValue[i+1]) - dp[i+2];
            }
            if(i < n-2){
                three = (stoneValue[i] + stoneValue[i+1] + stoneValue[i+2]) - dp[i+3];
            }

            dp[i] = max(one, max(two, three));
        }
        int ans = dp[0];
        if(ans == 0) return "Tie";
        else if(ans > 0) return "Alice";
        return "Bob";
    }
};