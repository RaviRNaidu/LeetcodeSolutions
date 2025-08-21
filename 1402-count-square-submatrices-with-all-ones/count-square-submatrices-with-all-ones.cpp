class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i][j] = matrix[i][j];
                if(i > 0 && j > 0){
                    if(matrix[i][j] == 1) {
                        dp[i][j] = 1 + min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                    }
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};