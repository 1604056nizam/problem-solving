class Solution {
public:
    void dfs(vector<vector<int>>&matrix, int i, int j) {
        if(i < 0 || i > matrix.size() - 1 || j < 0 || j > matrix[0].size() - 1 || matrix[i][j] != 0) {
            return;
        }
        matrix[i][j] = 2;

        dfs(matrix, i + 1, j);
        dfs(matrix, i - 1, j);

        dfs(matrix, i , j + 1);
        dfs(matrix, i , j - 1);
    }
    int regionsBySlashes(vector<string>& grid) {
        int row = grid.size();
        int column = grid[0].size();
        vector<vector<int>> matrix(row * 3, vector<int>(column * 3, 0));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (grid[i][j] == '/') {
                    matrix[i * 3][j * 3 + 2] = 1;
                    matrix[i * 3 + 1][j * 3 + 1] = 1;
                    matrix[i * 3 + 2][j * 3] = 1;
                } else if (grid[i][j] == '\\') {
                    matrix[i * 3][j * 3] = 1;
                    matrix[i * 3 + 1][j * 3 + 1] = 1;
                    matrix[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }
        int component = 0;

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    component++;
                    dfs(matrix, i , j);
                }
            }
        }
        return component;
    }
};