class Solution {
public:
    long long countValidSubstrings(string s) {
        int l = 0;
        int r = 0;
        long long ans = 0;
        int n = s.size();
        while(r < n){
            if(r > 1 && s.substr(r-2, 3) == "abc"){
                l = r - 1;
            }
            ans += (r-l+1);
            r++;
        }

        return ans;
    }
};