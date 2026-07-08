class Solution {
    bool isSafe(int row, int col, vector<string> &board, int n){
        //vertical
        for(int i=0;i<n;i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        //horizontal
        for(int i=0;i<n;i++){
            if(board[row][i] == 'Q'){
                return false;
            }
        }

        //left diagonal
        for(int i=row,j=col; i>=0 && j>=0; i--, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        //right diagonal
        for(int i=row,j=col; i>=0 && j<n; i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        return true;
    }
    
    void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int i=0;i<n;i++){
            if(isSafe(row, i, board, n)){
                board[row][i] = 'Q';
                nQueens(board, row+1, n, ans);
                board[row][i] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        nQueens(board, 0, n, ans);
        return ans;
    }
};