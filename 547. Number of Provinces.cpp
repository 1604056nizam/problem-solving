class Solution {
public:

    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int node) {
        visited[node] = true;
        for(int i = 0; i < isConnected[node].size(); i++) {
            if(isConnected[node][i] == 1 && !visited[i]) {
                dfs(isConnected, visited, i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool>visited(isConnected.size(), false);

        int numOfConnectedComponents = 0;

        for(int i = 0; i < visited.size(); i++) {
            if(!visited[i]) {
                dfs(isConnected, visited, i);
                numOfConnectedComponents++;
            }
        }

        return numOfConnectedComponents;
    }
};