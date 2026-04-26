class Solution {
    bool dfs(pair<int,int> node, pair<int,int> parent, vector<vector<char>>& grid, 
     vector<vector<int>> &vis, int drow[], int dcol[]){
        int n = grid.size();
        int m = grid[0].size();
        int row = node.first;
        int col = node.second;
        vis[row][col] = 1;
        char ch = grid[row][col];
        for(int i=0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            //if the ch is not visited
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == ch){
                if(dfs({nrow,ncol},{row,col},grid,vis,drow,dcol)) return true;
            }
            //if its visited but we'll check if its not parent
            //then we can say that cycle has been detected
            else if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == ch && vis[nrow][ncol]
              && !(nrow == parent.first && ncol == parent.second)){
                return true;
            }
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    if(dfs({i,j},{-1,-1},grid,vis,drow,dcol)) return true;
                }
            }
        }
        return false;
    }
};