class Solution {
public:

    vector<vector<string>> result;

    void nQueen(vector<string>& board, int col, vector<bool>& rowVec, vector<bool>& lowDiag, vector<bool>& upDiag) {

        if(col == board.size()) {
            result.push_back(board);
        }

        for(int row = 0; row < board.size(); row++) {
            if(rowVec[row] == false && lowDiag[row + col] == false && upDiag[board.size() + row - col] == false) {
                board[row][col] = 'Q';
                rowVec[row] = true;
                lowDiag[row + col] = true;
                upDiag[board.size() + row - col] = true;
                nQueen(board, col + 1, rowVec, lowDiag, upDiag);
                board[row][col] = '.';
                rowVec[row] = false;
                lowDiag[row + col] = false;
                upDiag[board.size() + row - col] = false;
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
       
        vector<string> board(n);
        string s(n, '.');

        for(int i = 0; i < n; i++) {
            board[i] = s;
        }
        
        vector<bool> rowVec(n, false);
        vector<bool> lowDiag(n * 2, false);
        vector<bool> upDiag(n * 2, false);

        nQueen(board, 0, rowVec, lowDiag, upDiag);

        return result;
    }
};