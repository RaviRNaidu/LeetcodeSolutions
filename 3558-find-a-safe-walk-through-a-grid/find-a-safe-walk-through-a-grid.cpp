class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, -1));
        queue<pair<int, pair<int, int>>> q;
        if(grid[0][0] == 1){
            health -= 1;
        }
        vis[0][0] = health;
        q.push({health, {0, 0}});
        while(!q.empty()){
            int remHealth = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            if(remHealth <= 0) continue;

            if(row == n-1 && col == m-1 && remHealth >= 1) return true;

            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    int newHealth = remHealth - grid[nrow][ncol];
                    if(newHealth > vis[nrow][ncol]){
                        vis[nrow][ncol] = newHealth;
                        q.push({newHealth, {nrow, ncol}});
                    }
                }
            }
        }
        return false;
    }
};