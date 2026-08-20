class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        vector<int> prev(m+1, 0);
        for(int i=1;i<=m;i++){
            prev[i] = i;
        }
        for(int i=1;i<=n;i++){
            vector<int> curr(m+1, 0);
            curr[0] = i;
            for(int j=1;j<=m;j++){
                if(word1[i-1] == word2[j-1]){
                    curr[j] = prev[j-1];
                }
                else{
                    int in = 1 + curr[j-1];
                    int del = 1 + prev[j];
                    int rep = 1 + prev[j-1];

                    curr[j] = min(in, min(del, rep));
                }
            }
            prev = curr;
        }
        return prev[m];;
    }
};