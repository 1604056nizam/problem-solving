class Solution {
public:
    bool dfs(vector<vector<char>>& grid, int i, int j, int parent_i, int parent_j, vector<vector<bool>>& visited, char matchingChar) {
        if(i < 0 || i > grid.size()  - 1 || j < 0 || j > grid[0].size() - 1) {
            return false;
        }

        if(visited[i][j] && grid[i][j] == matchingChar) return true;

        if(visited[i][j]) return false;

        visited[i][j] = true;

        int direction[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        for(auto& dir: direction) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            if(ni == parent_i && nj == parent_j) continue;
            if(ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && grid[ni][nj] == matchingChar) {
                if(dfs(grid, ni, nj, i, j, visited, matchingChar)) {
                    return true;
                }
            }
        }

        return false;

    }


    bool containsCycle(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(visited[i][j] == false) {
                    if( dfs(grid, i, j, -1 , -1, visited, grid[i][j])) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};