class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n){
        // check lcolumn
        for(int i=0; i<row; i++){
            if(board[i][col] == 'Q') return false;
        }

        // check left diagonal
        for(int i=row-1, j=col-1; i>=0&&j>=0; i--,j--){
            if(board[i][j] == 'Q') return false;
        }

        // check right diagnoal
        for(int i=row-1, j=col+1; i>=0&&j<n; i--,j++){
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
    void solve(vector<vector<string>>& ans, vector<string> board, int n, int row){
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int col=0; col<n; col++){
            if(isSafe(board, row, col, n)){
                board[row][col] = 'Q';
                solve(ans, board, n, row+1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(ans, board, n, 0);
        return ans;
    }
};