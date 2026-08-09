class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        vector<int> prev(n+1, 0);
        for(int i=1;i<=n;i++){
            vector<int> curr(n+1, 0);
            for(int j=1;j<=n;j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else{
                    int first = prev[j];
                    int second = curr[j-1];

                    curr[j] = max(first, second);
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};