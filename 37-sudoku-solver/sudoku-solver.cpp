class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        // Row check
        for(int i=0; i<9; i++){
            if(board[row][i] == c) return false;
        }
        // Col check
        for(int i=0; i<9; i++){
            if(board[i][col] == c) return false;
        }
        // box check
        int sr = (row/3)*3;
        int sc = (col/3)*3;
        for(int i=sr; i<sr+3; i++){
            for(int j=sc; j<sc+3; j++){
                if(board[i][j] == c) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == '.') {
                    for(char c='1'; c<='9'; c++){
                        if(isValid(board, i, j, c)){
                            board[i][j] = c;
                            if(solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};