class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int numOfEdges = edges.size();

        vector<int> parent(numOfEdges + 1);
        vector<int> rank(numOfEdges + 1);

        for(int i = 0 ; i <= numOfEdges; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        for(auto v : edges) {
            int element1 = v[0];
            int element2 = v[1];
            int parent1 = findParent(element1, parent);
            int parent2 = findParent(element2, parent);

            if(parent1 == parent2) return v;

            else {
                if(rank[parent1] < rank[parent2]) {
                    parent[parent2] = parent1;
                }
                else if(rank[parent2] < rank[parent1]) {
                    parent[parent1] = parent2;
                }
                else {
                    parent[parent1] = parent2;
                    rank[parent1]++;
                }
            }
        }

        return {};
    }

    int findParent(int element, vector<int>& parent) {
        if(parent[element] == element) return element;

        else return findParent(parent[element], parent);
    }
};