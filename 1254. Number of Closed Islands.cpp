class Solution {
public:
    int dfs(int i, int j, set<pair<int, int>>& visited, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return 0;
        }
        
        if (grid[i][j] == 1 || visited.find(make_pair(i, j)) != visited.end()) {
            return 1;
        }
        
        visited.insert(make_pair(i, j));
        return min({dfs(i + 1, j, visited, grid),
                    dfs(i - 1, j, visited, grid),
                    dfs(i, j + 1, visited, grid),
                    dfs(i, j - 1, visited, grid)});
    }

    int closedIsland(vector<vector<int>>& grid) {
        set<pair<int, int>> visited;
        int result = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0 && visited.find(make_pair(i, j)) == visited.end()) {
                    result += dfs(i, j, visited, grid);
                }
            }
        }
        return result;
        
    }
};