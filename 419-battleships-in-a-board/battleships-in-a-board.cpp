class Solution {
public:
    void DFS(vector<vector<char>>& board, int i, int j, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='.') return;
        board[i][j] = '.';
        DFS(board, i-1, j, n, m);
        DFS(board, i, j-1, n, m);
        DFS(board, i, j+1, n, m);
        DFS(board, i+1, j, n, m);
    }
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'X'){
                    DFS(board, i, j, n, m);
                    ans++;
                }
            }
        }
        return ans;
    }
};