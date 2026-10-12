class Solution {
    static bool com(string &s, string &t){
        return s.size() < t.size();
    }

    bool check(string&s, string& t){
        int i = 0;
        int j = 0;
        bool check = false;
        while(i < s.size()){
            if(s[i] == t[j]){
                i++;
                j++;
            }
            else{
                if(check) return false;
                check = true;
                j++;
            }
        }
        return true;
    }

    int recursion(int i, int j, vector<string>& words, int n, vector<vector<int>>& dp){
        if(i == 0) return dp[i][j] = 0;
        if(j < n+1 && words[i-1].size() != words[j-1].size() - 1) return dp[i][j] = recursion(i-1, j, words, n, dp);

        if(dp[i][j] != -1) return dp[i][j];

        int notTake = recursion(i-1, j, words, n, dp);
        int take = 0;
        if(j == n+1 || check(words[i-1], words[j-1])){
            take = 1 + recursion(i-1, i, words, n, dp);
        }

        return dp[i][j] = max(notTake, take);
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int ans = 1;
        sort(words.begin(), words.end(), com);
        vector<vector<int>> dp(n+1, vector<int> (n+2, -1));
        ans = max(ans, recursion(n, n+1, words, n, dp));

        return ans;
    }
};