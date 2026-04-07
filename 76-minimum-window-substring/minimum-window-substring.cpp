class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        int minLen = INT_MAX;
        int stInd = -1;
        int hash[256] = {0};
        for(int j=0;j<m;j++){
            hash[t[j]]++;
        }

        int l = 0;
        int r = 0;
        int cnt = 0;
        while(r < n){
            if(hash[s[r]] > 0){
                cnt++;
            }
            hash[s[r]]--;
            if(cnt == m){
                if(minLen > r-l+1){
                    minLen = r-l+1;
                    stInd = l;
                }
            }
            while(r < n && cnt == m){
                if(minLen > r-l+1){
                    minLen = r-l+1;
                    stInd = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        if(stInd == -1) return "";
        return s.substr(stInd,minLen);
    }
};