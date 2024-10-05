class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color, int currentColor) {
        color[node] = currentColor;

        for(auto neighbour: graph[node]) {
            if(color[neighbour] == -1) {
                if(!dfs(neighbour, graph, color, 1 - currentColor)) {
                    return false;
                }
            } else if(color[neighbour] == currentColor) {
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        
        for(int i = 0; i < graph.size(); i++) {
            if(color[i] == -1) {
                if(!dfs(i, graph, color, 0)) {
                    return false;
                }
            }
        }
        return true;
        
    }
};