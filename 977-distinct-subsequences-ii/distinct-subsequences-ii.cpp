class Solution {
public:
    int distinctSubseqII(string s) {
        int mod = 1e9 + 7;
        int n = s.size();
        long long hash[26] = {0};
        vector<long long> dp(n+1, 1);
        for(int i=1;i<=n;i++){
            if(hash[s[i-1] - 'a']){
                dp[i] = (2 * dp[i-1] - dp[hash[s[i-1] - 'a'] - 1] + mod) % mod; 
            }
            else{
                dp[i] = (2 * dp[i-1]) % mod;
            }
            hash[s[i-1] - 'a'] = i;
        }

        return (dp[n] - 1 + mod) % mod;
    }
};