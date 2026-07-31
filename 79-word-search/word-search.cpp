// bool bfs(int row, int col, vector<vector<char>>& board, string &word, int drow[], int dcol[], int n, int m){
    //     vector<vector<int>> vis(n, vector<int> (m,0));
    //     queue<pair<int, pair<int, int>>> q;
    //     q.push({0, {row, col}});
    //     vis[row][col] = 1;
    //     while(!q.empty()){
    //         int index = q.front().first;
    //         int r = q.front().second.first;
    //         int c = q.front().second.second;
    //         q.pop();

    //         if(index == word.size() - 1 && board[r][c] == word[index]){
    //             return true;
    //         }
            
    //         for(int i=0;i<4;i++){
    //             int nrow = r + drow[i];
    //             int ncol = c + dcol[i];
    //             if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == word[index+1]){
    //                 vis[nrow][ncol] = 1;
    //                 q.push({index+1,{nrow, ncol}});
    //             }
    //         }
    //     }
    //     return false;
    // }
class Solution {
    bool dfs(int row, int col, vector<vector<char>>& board, string &word,
     int drow[], int dcol[], int n, int m, int index){
        if(index == word.size() - 1 && board[row][col] == word[index]){
            return true;
        }
        char temp = board[row][col];
        board[row][col] = '#';
        for(int i=0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == word[index+1]){
                if(dfs(nrow, ncol, board, word, drow, dcol, n, m, index+1)){
                    board[row][col] = temp;
                    return true;
                }
            }
        }
        board[row][col] = temp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0]){
                    if(dfs(i,j,board,word, drow, dcol, n, m, 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};