class Solution {
    int recursion(int i, int j, string &word1, string &word2, vector<vector<int>>& dp){
        if(i == 0 && j == 0) return dp[i][j] = 0;
        if(i == 0 && j) return dp[i][j] = j;
        if(j == 0 && i) return dp[i][j] = i;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i-1] == word2[j-1]){
            return dp[i][j] = recursion(i-1, j-1, word1, word2, dp);
        }

        int in = 1 + recursion(i, j-1, word1, word2, dp);
        int del = 1 + recursion(i-1, j, word1, word2, dp);
        int rep = 1 + recursion(i-1, j-1, word1, word2, dp);

        return dp[i][j] = min(in, min(del, rep));
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return recursion(n, m, word1, word2, dp);
    }
};