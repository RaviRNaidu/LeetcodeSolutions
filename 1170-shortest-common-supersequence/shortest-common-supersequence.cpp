class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    int first = dp[i-1][j];
                    int second = dp[i][j-1];
                    dp[i][j] = max(first, second);
                }
            }
        }
        int lcs = dp[n][m];
        int size = (n + m) - lcs;
        string ans(size, '$');
        int index = size - 1;
        int i = n;
        int j = m;
        while(i > 0 && j > 0){
            int left = dp[i][j-1];
            int up = dp[i-1][j];
            if(dp[i][j] > left && dp[i][j] > up){
                ans[index] = str1[i-1];
                i--;
                j--;
            }
            else if(dp[i][j] == left){
                ans[index] = str2[j-1];
                j--;
            }
            else{
                ans[index] = str1[i-1];
                i--;
            }
            index--;
        }

        while(i > 0){
            ans[index] = str1[i-1];
            i--;
            index--;
        }
        while(j > 0){
            ans[index] = str2[j-1];
            j--;
            index--;
        }

        return ans;
    }
};