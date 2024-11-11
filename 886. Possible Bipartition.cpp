class Solution {
public:
    bool dfs(int node, unordered_map<int, vector<int>>& adjacentList, vector<int>& color, int currentColor) {
        color[node] = currentColor;

        for(auto neighbour: adjacentList[node]) {
            if(color[neighbour] == -1) {
                if(!dfs(neighbour, adjacentList, color, 1 - currentColor)) {
                    return false;
                }
            }
            else if(color[neighbour] == currentColor) {
                return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> adjacentList;
        vector<int> color(n+1, -1);

        for(int i = 0; i < dislikes.size(); i++) {
            adjacentList[dislikes[i][0]].push_back(dislikes[i][1]);
            adjacentList[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        for(int i = 1; i <= n; i++) {
            if(color[i] == -1) {
                if(!dfs(i, adjacentList, color, 0)) {
                    return false;
                }
            }
        }
        return true;
        
    }
};