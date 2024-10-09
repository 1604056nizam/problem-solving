class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rowPlusColumn = grid.size() + grid[0].size();
        int rows = grid.size(), cols = grid[0].size(), serverCount = 0; 
        vector<int> rowCount(rows, 0), colCount(cols, 0);
    

        for(int i = 0 ; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    serverCount++;
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }

        
        
        int isolatedServers = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1 && rowCount[i] == 1 && colCount[j] == 1) {
                    isolatedServers++; 
                }
            }
        }

        return serverCount - isolatedServers;


    }
};