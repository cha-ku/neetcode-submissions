class Solution {
    bool dfs(vector<vector<char>>& board, const string& word, const int pos, int num_rows, int num_cols, int row, int col) {
        if (row < 0 || row >= num_rows || col < 0 || col >= num_cols) {
            return false;
        }
        bool is_found = false;
        char c = word[pos];
        if (board[row][col] == word[pos]) {
            board[row][col] = '#';
            if (pos == word.size()-1) {
                return true;
            }
            is_found = dfs(board, word, pos+1, num_rows, num_cols, row+1, col) ||
                       dfs(board, word, pos+1, num_rows, num_cols, row-1, col) ||
                       dfs(board, word, pos+1, num_rows, num_cols, row, col-1) ||
                       dfs(board, word, pos+1, num_rows, num_cols, row, col+1);
            board[row][col] = c;
        }
        return is_found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int num_rows = board.size();
        int num_cols = board[0].size();
        bool found = false;
        for (int r = 0; r < num_rows && !found; ++r) {
            for (int c = 0; c < num_cols && !found; ++c) {
                found = dfs(board, word, 0, num_rows, num_cols, r, c);
            }
        } 
        return found;
    }
};
