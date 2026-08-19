class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<long long> prev(m+1, 0);
        prev[0] = 1;
        for(int i=1;i<=n;i++){
            vector<long long> curr(m+1, 0);
            curr[0] = 1;
            for(int j=1;j<=m;j++){
                int take = 0;
                if(s[i-1] == t[j-1]){
                    take = prev[j-1];
                }

                long long notTake = prev[j];
                curr[j] = take + notTake;
            }
            prev = curr;
        }
        return (int)prev[m];
    }
};