class DisjointSet {
        vector<int> parent, rank, size;
        public:
        DisjointSet(int n) {
            rank.resize(n+1, 1);
            size.resize(n+1, 1);
            parent.resize(n+1);

            for(int i = 0; i <= n; i++) {
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
            else if(rank[parent1] < rank[parent2]) {
                parent[parent1]  = parent2;
            }
            else if(rank[parent2] < rank[parent1]) {
                parent[parent2] = parent1;
            } else {
                parent[parent2] = parent1;
                rank[parent1]++;
            }

        }
        
        void unionBySize(int element1, int element2) {
            int parent1 = findParent(element1);
            int parent2 = findParent(element2);

            if(parent1 == parent2) return;

            if(size[parent1] < size[parent2]) {
                parent[parent1] = parent2;
                size[parent2] += size[parent1];
            } else {
                parent[parent2] = parent1;
                size[parent1] += size[parent2];
            }
        }
        
    };


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxColumn = 0, numberOfComponent = 0;

        for(auto it: stones) {
            maxRow = max(maxRow, it[0]);
            maxColumn = max(maxColumn, it[1]);
        }

        DisjointSet ds(maxRow + maxColumn + 1);
        unordered_map<int, int> allNodes;

        for(auto it: stones) {
            int row = it[0];
            int column = it[1] + maxRow + 1;

            ds.unionBySize(row, column);
            allNodes[row] = 1;
            allNodes[column] = 1;
        }  

        for(auto it: allNodes) {
            if (ds.findParent(it.first) == it.first) {
                numberOfComponent++;
            }
        }

        return stones.size() - numberOfComponent;
    }
};