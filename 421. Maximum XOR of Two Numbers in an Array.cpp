struct Node {
    Node* links[2];

    Node* get(int n) {
        return links[n];
    }

    void put(int n, Node* newNode) {
        links[n] = newNode;
    }
};

class Trie {
    private:
    Node* root;

    public:

    Trie() {
        root = new Node();
    }

    void insert(int n) {
        Node* node = root;
        unsigned int mask = 1 << 31;

        for(int i = 0; i < 32; i++) {
            int bit = (n & mask) ? 1 : 0;
            if(!node->get(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
            n = n << 1;
        }
    }

    int findMaximumXOROfNumber(int n) {
        Node* node = root;
        int result = 0;
        unsigned int mask = 1 << 31;

        for(int i = 0; i < 32; i++) {
            int bit = (n & mask) ? 1 : 0;
            int oppositeBit = 1 - bit;
            result = result << 1;

            if(node->get(oppositeBit)) {
                result = result | 1;
                node = node->get(oppositeBit);
            } else {
                result = result | 0;
                node = node->get(bit);
            }

            n = n << 1;
        }

        return result;
    }


};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* obj = new Trie();
        int result = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {
            obj->insert(nums[i]);
        }

        for(int i = 0; i < nums.size(); i++) {
            result = max(obj->findMaximumXOROfNumber(nums[i]), result);
        }

        return result;


    }
};