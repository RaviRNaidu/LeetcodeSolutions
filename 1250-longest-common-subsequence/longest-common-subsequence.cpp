class Solution {
    int recursion(string& s1, string& s2, int i, int j, vector<vector<int>>& dp){
        if(i == 0 || j == 0) return dp[i][j] = 0;

        if(dp[i][j] != -1) return dp[i][j];

        int noMatch = max(recursion(s1, s2, i-1, j, dp), recursion(s1, s2, i, j-1, dp));
        int match = 0;
        if(s1[i-1] == s2[j-1]) match = 1 + recursion(s1, s2, i-1, j-1, dp);

        return dp[i][j] = max(match, noMatch);
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return recursion(text1, text2, n, m, dp);
    }
};