class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        unordered_map<int, int> mpp;
        int i = 0;
        int j = 0;
        int ans = 0;
        while(j < n){
            mpp[s[j]]++;

            while(mpp[s[j]] > 2 && i < j){
                mpp[s[i]]--;
                i++;
            }
            ans = max(j-i+1, ans);
            j++;
        }
        return ans;
    }
};