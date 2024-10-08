class DisjointSet{ 
    vector<int> parent, rank, size;

    public: 
    DisjointSet(int n) {
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
            parent[parent2] = parent1;
            rank[parent1]++;
        }
    }
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        DisjointSet ds(n);
        vector<int>parentCount(n , 0);

        for(int i = 0; i < n; i++) {
            int currentNodeParent = ds.findParent(i);
            if(leftChild[i] != -1) {
                int leftParent = ds.findParent(leftChild[i]);
                
                if(currentNodeParent == leftParent || parentCount[leftChild[i]]) {
                    return false;
                }

                ds.unionByRank(i, leftChild[i]);
                parentCount[leftChild[i]]++;
            }

            if(rightChild[i] != -1) {
                int rightParent = ds.findParent(rightChild[i]);

                if(currentNodeParent == rightParent || parentCount[rightChild[i]]) {
                    return false;
                }

                ds.unionByRank(i, rightChild[i]);
                parentCount[rightChild[i]]++;
            }
        }
        int component = 0;

        for(int i = 0; i < n; i++) {
            if(ds.findParent(i) == i) {
                component++;
            }
        }

        return component == 1;
    }
};