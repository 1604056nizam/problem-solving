class Solution {
public:
    bool checkDirectedGraphCycleUsingDfs(int node, vector<vector<int>>& graph,
                                         vector<int>& visited,
                                         vector<int>& pathVisited,
                                         vector<int>& safeNode) {

        visited[node] = 1;
        pathVisited[node] = 1;
        for (auto neighbour : graph[node]) {
            if (!visited[neighbour]) {
                if (checkDirectedGraphCycleUsingDfs(neighbour, graph, visited,
                                                    pathVisited, safeNode)) {
                    safeNode[node] = 0;
                    return true;
                }
            } else {
                if (pathVisited[neighbour]) {
                    safeNode[node] = 0;
                    return true;
                }
            }
        }

        pathVisited[node] = 0;
        safeNode[node] = 1;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(), 0), pathVisited(graph.size(), 0),
            safeNode(graph.size(), 0), result;

        for (int i = 0; i < graph.size(); i++) {
            if (!visited[i]) {
                checkDirectedGraphCycleUsingDfs(i, graph, visited, pathVisited, safeNode);
            }
        }

        for (int i = 0; i < safeNode.size(); i++) {
            if (safeNode[i])
                result.push_back(i);
        }

        return result;
    }
};