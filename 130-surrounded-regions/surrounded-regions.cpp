class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j, int m, int n){
        if(i>=n || j>=m || i<0 || j<0 || board[i][j] != 'O') return;
        board[i][j] = '#';
        dfs(board, i+1, j, m, n); 
        dfs(board, i, j+1, m, n); 
        dfs(board, i-1, j, m, n); 
        dfs(board, i, j-1, m, n); 
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        // LEFT & RIGHT
        for(int i=0; i<board.size(); i++){
            dfs(board, i, 0, m, n);
            dfs(board,i, m-1, m, n);
        }
        // TOP & BOTTOM
        for(int j=0; j<board[0].size(); j++){
            dfs(board, 0, j, m, n);
            dfs(board, n-1, j, m, n);
        }
        // FLIP INTERIROR O->X
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};