/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    map<Node*, Node*> visited;

    Node* createNode(Node* head) {
        if(!head) return nullptr;

        Node* temp = new Node(head->val);
        visited[head] = temp;
        temp->next = createNode(head->next);

        return temp;
    }

    Node* copyRandomList(Node* head) {
        Node* start = createNode(head);

        while(head) {
            visited[head]->random = visited[head->random];
            head = head->next;
        }

        return start;
    }
};