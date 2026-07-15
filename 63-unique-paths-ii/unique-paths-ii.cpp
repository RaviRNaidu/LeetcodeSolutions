class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<int> prev(m+1, 0);
        for(int i=1;i<=n;i++){
            vector<int> curr(m+1, 0);
            for(int j=1;j<=m;j++){
                if(i == 1 && j == 1 && !obstacleGrid[i-1][j-1]){
                    curr[j] = 1;
                }
                else if(obstacleGrid[i-1][j-1]){
                    curr[j] = 0;
                }
                else{
                    int left = curr[j-1];
                    int up = prev[j];

                    curr[j] = left + up;
                } 
            }
            prev = curr;
        }
        return prev[m];
    }
};