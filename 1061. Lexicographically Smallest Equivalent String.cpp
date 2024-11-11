class DisjointSet {
    vector<int> parent, rank, size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
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

    void unionByLexoGraphicalOrder(int element1, int element2) {
        int parent1 = findParent(element1);
        int parent2 = findParent(element2);

        if (parent1 == parent2)
            return;

        if (parent1 < parent2) {
            parent[parent2] = parent1;
        } else {
            parent[parent1] = parent2;
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet ds(25);
        for (int i = 0; i < s1.size(); i++) {
            int first = s1[i] - 'a';
            int second = s2[i] - 'a';
            ds.unionByLexoGraphicalOrder(first, second);
        }

        string result = "";
        for (int i = 0; i < baseStr.size(); i++) {
            int element = baseStr[i] - 'a';
            int parent = ds.findParent(element);
            char subResult = parent + 'a';
            result += subResult;
        }
        return result;
    }
};