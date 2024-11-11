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

    void unionByLexographical(int element1, int element2) {
        int parent1 = findParent(element1);
        int parent2 = findParent(element2);

        if(parent1 == parent2) return;

        if(parent1 < parent2) {
            parent[parent2] = parent1;
            rank[element1]++;
        } else {
            parent[parent1] = parent2;
            rank[element2]++;
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        Disjointset ds(s.size());
        unordered_map<int, vector<int>> childParentRel;

        for(int i = 0 ; i < pairs.size(); i++) {
            int element1 = pairs[i][0];
            int element2 = pairs[i][1];
            ds.unionByLexographical(element1, element2);
        }

        for(int i = 0 ; i < s.size(); i++) {
            int parent = ds.findParent(i);
            childParentRel[parent].push_back(i);
        }

        for(auto& it : childParentRel) {
            vector<int>& eachGroup = it.second;
            string temp = "";

            for(int i = 0 ; i < eachGroup.size(); i++) {
                temp.push_back(s[eachGroup[i]]) ;
            }
            sort(temp.begin(), temp.end());

            for(int i = 0; i< eachGroup.size(); i++) {
                s[eachGroup[i]] = temp[i];
            }
        }

        return s;
    }
};