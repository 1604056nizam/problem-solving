class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>result(mat.size(), vector<int>(mat[0].size(), -1));
        vector<vector<int>>visited(mat.size(), vector<int>(mat[0].size(), 0));
        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[0].size(); j++) {
                if(mat[i][j] == 0) {
                    result[i][j] = 0;
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < q.size(); i++){
                int row = q.front().first.first;
                int col = q.front().first.second;
                int currentDistance = q.front().second;
                q.pop();

                int dr[4] = {0, -1, 0, 1};
                int dc[4] = {-1, 0, 1, 0};

                for(int j = 0; i < 4; i++) {
                    int nr = row + dr[j];
                    int nc = col + dc[j];
                    if(nr < 0 || nr > mat.size() - 1 || nc < 0 || nc > mat[0].size() - 1 || visited[nr][nc] == 1) {
                        continue;
                    }

                    result[nr][nc] = currentDistance + 1;
                    visited[nr][nc] = 1;
                    q.push({{nr, nc}, result[nr][nc]});
                }
            }
        }

        return result;
    }
};