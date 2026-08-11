class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        vector<int> prev(n+1, 0);
        for(int i=1;i<=n;i++){
            vector<int> curr(n+1, 0);
            for(int j=1;j<=n;j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else{
                    int up = prev[j];
                    int down = curr[j-1];

                    curr[j] = max(up, down);
                }
            }
            prev = curr;
        }
        int ans = prev[n];
        return n - ans;
    }
};