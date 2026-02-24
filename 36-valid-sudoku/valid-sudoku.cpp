class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false};
        bool cols[9][9] = {false};
        bool box[9][9] = {false};
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == '.') continue;
                int d = board[i][j] - '1';
                int b = (i/3)*3+(j/3);
                if(row[i][d] || cols[j][d] || box[b][d])
                    return false;
                row[i][d] = true;
                cols[j][d] = true;
                 box[b][d] = true;
            }
        }
        return true;
    }
};