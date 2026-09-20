class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int cnt = 26;
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = ans + ((cnt - (s[i] - 'a')) * (i+1));
        }
        return ans;
    }
};