class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        queue<pair<int, int>>q;
        int rottenOrange = 0, freshOrange;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j] = 1;
                    rottenOrange++;
                } else if(grid[i][j] == 1) {
                    freshOrange++;
                }
            }
        }
        if(rottenOrange == 0 && freshOrange == 0) return 0;
        int minutes = -1;

        while(!q.empty()) {
            int size = q.size();
            minutes++;
            for(int k = 0; k < size; k++) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                if(i + 1 < grid.size() && grid[i + 1][j] == 1 && visited[i + 1][j] == 0) {
                    visited[i + 1][j] = 1;
                    grid[i + 1][j] = 2;
                    q.push({i + 1, j});
                }
                if(i - 1 >= 0 && grid[i - 1][j] == 1 && visited[i - 1][j] == 0) {
                    visited[i - 1][j] = 1;
                    grid[i - 1][j] = 2;
                    q.push({i - 1, j});
                }
                if(j + 1 < grid[0].size() && grid[i][j + 1] == 1 && visited[i][j + 1] == 0) {
                    visited[i][j + 1] = 1;
                    grid[i][j + 1] = 2;
                    q.push({i, j + 1});
                }
                if(j - 1 >= 0 && grid[i][j - 1] == 1 && visited[i][j - 1] == 0) {
                    visited[i][j - 1] = 1;
                    grid[i][j - 1] = 2;
                    q.push({i, j - 1});
                }
            }
        }

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return minutes;
    }
};