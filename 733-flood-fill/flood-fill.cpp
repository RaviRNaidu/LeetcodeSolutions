class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<pair<int, int>> q;
        q.push({sr, sc});

        int iniColor = image[sr][sc];
        vis[sr][sc] = 1;
        int dRow[4] = {-1, 0, 1, 0};
        int dCol[4] = {0, 1, 0, -1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            image[row][col] = color;

            for(int i=0;i<4;i++){
                int nrow = row + dRow[i];
                int ncol = col + dCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && image[nrow][ncol] == iniColor)
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        return image;
    }
};