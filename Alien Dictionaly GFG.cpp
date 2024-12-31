class Solution {
  public:
    string findOrder(vector<string> dict, int k) {
        // code here
        vector<int> inDegree(k, 0);
        string result = "";
        vector<int>adj[k];
        queue<int> q;
        
        for(int i = 0; i < dict.size() -1; i++) {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.size() , s2.size());
            
            for(int j = 0; j < len; j++) {
                if(s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    inDegree[s2[j] - 'a'] ++;
                    break;
                }
            }
        }
        
        for(int i = 0; i < inDegree.size(); i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            result += (node + 'a');
            
            for(auto nei: adj[node]) {
                inDegree[nei] -= 1;
                if(inDegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }
        
        if(result.size() == k) {
            return result;
        }
        
        return "";
        
    }
};