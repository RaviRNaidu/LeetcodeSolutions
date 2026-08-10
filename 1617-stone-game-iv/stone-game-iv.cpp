class Solution {
    bool recursion(int n, vector<int> &dp){
        if(n == 0) return dp[n] = false;
        if(n == 1) return dp[n] = true;

        if(dp[n] != -1) return dp[n];

        bool check = false;
        for(int i=1;i*i<=n;i++){
            bool temp = recursion(n - (i*i), dp);
            if(temp == false){
                check = true;
                break;
            }
        }

        return dp[n] = check;
    }
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1, false);
        dp[1] = true;
        for(int j=2;j<=n;j++){
            bool check = false;
            for(int i=1;i*i<=j;i++){
                bool temp = dp[j - (i*i)];
                if(temp == false){
                    check = true;
                    break;
                }
            }

            dp[j] = check;
        }
        return dp[n];
    }
};