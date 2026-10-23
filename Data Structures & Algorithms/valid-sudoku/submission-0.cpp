class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int num_rows = board.size();
        int num_cols = board[0].size();
        for (int r = 0; r < num_rows; ++r) {
            unordered_set<char> row_seen;
            for (int c = 0; c < num_cols; ++c) {
                char elem = board[r][c];
                if (elem == '.') {
                    continue;
                }
                if (row_seen.contains(elem)) {
                    return false;
                }
                row_seen.insert(elem);
            }
        }
        for (int c = 0; c < num_cols; ++c) {
            unordered_set<char> col_seen;
            for (int r = 0; r < num_rows; ++r) {
                char elem = board[r][c];
                if (elem == '.') {
                    continue;
                }
                if (col_seen.contains(elem)) {
                    return false;
                }
                col_seen.insert(elem);
            }
        }

        for (int i = 0; i < 9; ++i) {
            unordered_set<char> square_seen;
            for (int r = 0; r < 3; ++r) {
                for (int c = 0; c < 3; ++c) {
                    // square 0 - 0,0 0,1 0,2 1,0 1,1 1,2 2,0 2,1 2,2
                    // square 1 - 0,3 0,4 0,5 1,3 1,4 1,5 2,3 2,4 2,5
                    // square 2 - 0,6 0,7 0,8 1,6 1,7 1,8 2,6 2,7 2,8
                    int row = (i/3) * 3 + r;
                    int col = (i%3) * 3 + c;
                    char elem = board[row][col];
                    if (elem == '.') {
                        continue;
                    }
                    if (square_seen.contains(elem)) {
                        return false;
                    }
                    square_seen.insert(elem);
                }
            }
        }
        return true;
    }
};
