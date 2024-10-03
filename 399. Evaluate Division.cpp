class Solution {
public:
    unordered_map<string, unordered_map<string, double>>
    buildGraph(vector<vector<string>>& equations, vector<double>& values) {
        unordered_map<string, unordered_map<string, double>> graph;

        for (int i = 0; i < equations.size(); i++) {
            string divident = equations[i][0];
            string divisor = equations[i][1];
            graph[divident][divisor] = values[i];
            graph[divisor][divident] = 1 / values[i];
        }

        return graph;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        unordered_map<string, unordered_map<string, double>> graph =
            buildGraph(equations, values);
        vector<double> finalAns;

        for (int i = 0; i < queries.size(); i++) {
            string dividend = queries[i][0];
            string divisor = queries[i][1];

            if (graph.find(divisor) == graph.end() ||
                graph.find(dividend) == graph.end()) {
                finalAns.push_back(-1);
            } else {
                unordered_set<string> visited;
                double ans = -1, temp = 1;
                dfs(graph, visited, ans, temp, dividend, divisor);
                finalAns.push_back(ans);
            }
        }
        return finalAns;
    }

    void dfs(unordered_map<string, unordered_map<string, double>>& graph,
             unordered_set<string>& visited, double& ans, double temp,
             string node, string destination) {
        if (visited.find(node) != visited.end())
            return;

        visited.insert(node);
        if (node == destination) {
            ans = temp;
            return;
        }

        for (auto neighbour : graph[node]) {
            dfs(graph, visited, ans, temp * neighbour.second, neighbour.first,
                destination);
        }
    }
};