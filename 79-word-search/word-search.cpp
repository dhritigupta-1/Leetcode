class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, int i, int j, int start){
        if(start == word.length()) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] != word[start]) return false;
        char temp = board[i][j];
        board[i][j] = '#'; // mark visited
        bool found = solve(board, word, i-1, j, start+1) ||
                     solve(board, word, i+1, j, start+1) ||
                     solve(board, word, i, j-1, start+1) ||
                     solve(board, word, i, j+1, start+1);
        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
               if(solve(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};