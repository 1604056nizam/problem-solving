class Disjointset {
    vector<int> parent, rank, size;

    public:
    Disjointset(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int element) {
        if(parent[element] == element) return element;

        return parent[element] = findParent(parent[element]);
    }

    void unionByRank(int element1, int element2) {
        int parent1 = findParent(element1);
        int parent2 = findParent(element2);

        if(parent1 == parent2) return;

        if(rank[parent1] < rank[parent2]) {
            parent[parent1] = parent2;
        } else if(rank[parent2] < rank[parent1]) {
            parent[parent2] = parent1;
        } else {
            parent[parent1] = parent2;
            rank[parent2]++;
        }
    }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjointset ds(n);
        int extraCable = 0;

        for(int i = 0; i < connections.size(); i++) {
             if(ds.findParent(connections[i][0]) == ds.findParent(connections[i][1])) {
                extraCable++;
            }
            ds.unionByRank(connections[i][0], connections[i][1]);
        }

        int component = 0;
        for(int i = 0; i < n; i++) {
            if(ds.findParent(i) == i) {
                component++;
            }
        }


        if(extraCable >= (component - 1) ) {
            return component - 1;
        } else {
            return -1;
        }
    }
};