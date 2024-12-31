class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        vector<vector<int>>visited(grid.size(), vector<int>(grid[0].size(), 0));
        queue<pair<int, int>> q;
        int baseX, baseY, row, col, nr, nc;
        int dr[4] = {0, -1, 0, 1};
        int dc[4] = {-1, 0, 1, 0};
        set<vector<pair<int, int>>> result;
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    baseX = i;
                    baseY = j;
                    q.push({i, j});
                    vector<pair<int, int>> subResult;
                    
                    while(!q.empty()) {
                        row = q.front().first;
                        col = q.front().second;
                        q.pop();
                        visited[row][col] = 1;
                        
                        subResult.push_back({row - baseX, col - baseY});
                        
                        for(int j = 0; j < 4; j++) {
                            nr = row + dr[j];
                            nc = col + dc[j];
                            
                            if(nr >=0 && nr < grid.size() && nc >=0 && nc < grid[0].size() && grid[nr][nc] == 1 && !visited[nr][nc]) {
                                q.push({nr, nc});
                                visited[nr][nc] = 1;
                            }
                        }
                    }
                    
                    result.insert(subResult);
                }
            }
        }
        
        return result.size();
    }
};