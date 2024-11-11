class DisjointSet {
    vector<int> parent, rank, size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int element) {
        if (parent[element] == element)
            return element;

        return parent[element] = findParent(parent[element]);
    }

    void unionByRank(int element1, int element2) {
        int parent1 = parent[element1];
        int parent2 = parent[element2];

        if (parent1 == parent2)
            return;

        if (rank[parent1] < rank[parent2]) {
            parent[parent1] = parent2;
        } else if (rank[parent2] < rank[parent1]) {
            parent[parent2] = parent1;
        } else {
            parent[parent1] = parent2;
            rank[parent1]++;
        }
    }

    void unionBySize(int element1, int element2) {
        int parent1 = parent[element1];
        int parent2 = parent[element2];

        if (parent1 == parent2)
            return;

        if (size[parent1] < size[parent2]) {
            parent[parent1] = parent2;
            size[parent2] += size[parent1];
        } else {
            parent[parent2] = parent[parent1];
            size[parent1] += size[parent2];
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DisjointSet ds(25);
        for (int i = 0; i < equations.size(); i++) {
            if (equations[i][1] == '=') {
                int first = equations[i][0] - 'a';
                int second = equations[i][3] - 'a';
                ds.unionBySize(first, second);
            }
        }

        for (int i = 0; i < equations.size(); i++) {
            if (equations[i][1] == '!') {
                int parent1 = ds.findParent(equations[i][0] - 'a');
                int parent2 = ds.findParent(equations[i][3] - 'a');

                if (parent1 == parent2) {
                    return false;
                }
            }
        }
        return true;
    }
};