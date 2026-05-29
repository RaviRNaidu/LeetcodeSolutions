class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> ans(n, vector<int> (m));
        vector<vector<int>> vis(n, vector<int> (m,0));

        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j] == 1){
                    ans[i][j] = 0;
                    vis[i][j] = 1;
                    q.push({0,{i,j}});
                }
            }
        }

        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0 , -1};
        while(!q.empty()){
            int height = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && isWater[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    ans[nrow][ncol] = height + 1;
                    q.push({height + 1, {nrow,ncol}});
                }
            }
        }

        return ans;
    }
};