class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, int &currentArea, int &ans) {
        if(i < 0 || i > grid.size() - 1 || j < 0  || j > grid[0].size() -1 || grid[i][j] != 1) {
            if(currentArea > ans) {
                ans = currentArea;
            }

            return;
        }
        grid[i][j] = 2;
        currentArea += 1;
        dfs(i + 1, j, grid, currentArea, ans);
        dfs(i - 1, j, grid, currentArea, ans);
        dfs(i, j + 1, grid, currentArea, ans);
        dfs(i, j - 1, grid, currentArea, ans);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;

        for(int i = 0 ; i < grid.size(); i++) {
            for(int j = 0 ; j < grid[0].size(); j++) {
                if(grid[i][j] != 1){
                    continue;
                }
                int currentArea = 0;
                dfs(i , j, grid, currentArea, ans);
            }
        }

        return ans;
    }
};