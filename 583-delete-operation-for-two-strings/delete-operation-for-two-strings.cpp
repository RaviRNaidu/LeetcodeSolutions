class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> prev(m+1, 0);
        for(int i=1;i<=n;i++){
            vector<int> curr(m+1, 0);
            for(int j=1;j<=m;j++){
                if(word1[i-1] == word2[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else{
                    int first = prev[j];
                    int second = curr[j-1];

                    curr[j] = max(first, second);
                }
            }
            prev = curr;
        }
        int ans = prev[m];
        return (n + m) - 2 * ans;
    }
};