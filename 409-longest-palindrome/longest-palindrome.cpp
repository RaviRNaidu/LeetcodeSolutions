class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        unordered_map<char, int> mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
        int ans = 0;
        bool flag = true;
        for(auto it : mpp){
            if(it.second % 2 == 0){
                ans += it.second;
            }
            else if(it.second % 2 != 0){
                ans += it.second - 1;
                if(flag){
                    ans += 1;
                    flag = false;
                }
            }
        }
        return ans;
    }
};