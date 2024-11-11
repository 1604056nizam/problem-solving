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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int size = accounts.size();

        DisjointSet ds(size);
        unordered_map<string, int> mapMailToNode;

        for(int i = 0; i< accounts.size(); i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                if(mapMailToNode.find(accounts[i][j]) == mapMailToNode.end()) {
                    mapMailToNode[accounts[i][j]] = i;
                } else {
                    ds.unionBySize(i, mapMailToNode[accounts[i][j]]);
                }
            }
        }

        vector<vector<string>> mergedAccount(size + 1);
        for(auto it: mapMailToNode) {
            string mail = it.first;
            int parent = ds.findParent(it.second);
            mergedAccount[parent].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i = 0; i < mergedAccount.size(); i ++) {
            if (mergedAccount[i].size() == 0) continue;
            string name = accounts[i][0];
            vector<string> temp;
            temp.push_back(name);
            sort(mergedAccount[i].begin(), mergedAccount[i].end());
            for(auto it: mergedAccount[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
            
        }
        return ans;        
    }
};