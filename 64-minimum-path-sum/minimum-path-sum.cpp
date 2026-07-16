class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> prev(m+1, 1e9);
        for(int i=1;i<=n;i++){
            vector<int> curr(m+1, 1e9);
            for(int j=1;j<=m;j++){
                if(i == 1 && j == 1){
                    curr[j] = grid[i-1][j-1];
                }
                else{
                    int up = grid[i-1][j-1] + prev[j];
                    int left = grid[i-1][j-1] + curr[j-1];
                    curr[j] = min(up, left);
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};