class Solution {
public:
    int row, col;
    void capture(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i > row - 1 || j < 0 || j > col - 1 ||
            board[i][j] != 'O') {
            return;
        }

        board[i][j] = 'T';
        capture(board, i + 1, j);
        capture(board, i - 1, j);
        capture(board, i, j + 1);
        capture(board, i, j - 1);
    }

    void solve(vector<vector<char>>& board) {
        row = board.size(), col = board[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if ((i == 0 || i == row - 1 || j == 0 || j == col - 1) &&
                    board[i][j] == 'O') {
                    capture(board, i, j);
                }
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
    }
};