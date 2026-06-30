class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        long long ans = 0;
        for(int i=0;i<n;i++){
            int hash[3] = {0};
            int cnt = 0;
            for(int j=i;j<n;j++){
                if(hash[s[j] - 'a'] == 0){
                    hash[s[j] - 'a'] = 1;
                    cnt++;
                }
                if(cnt == 3){
                    ans += (n - j);
                    break;
                }
            }
        }
        return ans;
    }
};