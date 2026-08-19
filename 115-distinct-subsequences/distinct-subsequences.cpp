class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<long long> prev(m+1, 0);
        prev[0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                int take = 0;
                if(s[i-1] == t[j-1]){
                    take = prev[j-1];
                }

                long long notTake = prev[j];
                prev[j] = take + notTake;
            }
        }
        return (int)prev[m];
    }
};