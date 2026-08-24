class Solution {
    bool recursion(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return dp[i][j] = true;
        if(j == 0 && i) return dp[i][j] = false;

        if(dp[i][j] != -1) return dp[i][j];

        if(i && (s[i-1] == p[j-1] || p[j-1] == '?')){
            return dp[i][j] = recursion(i-1, j-1, s, p, dp);
        }
        bool ans = false;
        if(p[j-1] == '*'){
            for(int ind=0;ind<=i;ind++){
                ans = (ans || recursion(i-ind, j-1, s, p, dp));
            } 
        }
        return dp[i][j] = ans;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return recursion(n, m, s, p, dp);
    }
};