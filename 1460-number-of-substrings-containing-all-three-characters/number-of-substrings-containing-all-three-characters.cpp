class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        long long ans = 0;
        int l = 0;
        int r = 0;
        int hash[3] = {0};
        while(r < n){
            hash[s[r] - 'a']++;
            while(hash[0] != 0 && hash[1] != 0 && hash[2] != 0){
                ans += (n - r);
                hash[s[l] - 'a']--;
                l++;
            }
            r++;
        }
        return ans;
    }
};