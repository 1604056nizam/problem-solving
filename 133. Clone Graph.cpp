/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> visited;
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;

        if(visited.find(node) != visited.end()) {
            return visited[node];
        }

        Node* copyNode = new Node(node->val);
        visited[node] = copyNode;
        
        for(auto neighbors: node->neighbors) {
            copyNode->neighbors.push_back(cloneGraph(neighbors));
        }

        return copyNode;
    }
};