class Solution {
    // int recursion(int i, int j, vector<vector<int>> &dp){
    //     if(i == 0 || j == 0) return 0;
    //     if(i == 1 && j == 1) return dp[i][j] = 1;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int up = recursion(i-1, j, dp);
    //     int left = recursion(i, j-1, dp);
    //     return dp[i][j] = (up + left);
    // }
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n+1, 0);
        for(int i=1;i<=m;i++){
            vector<int> curr(n+1, 0);
            for(int j=1;j<=n;j++){
                if(i == 1 && j == 1){
                    curr[j] = 1;
                }
                else{
                    int up = prev[j];
                    int left = curr[j-1];
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};