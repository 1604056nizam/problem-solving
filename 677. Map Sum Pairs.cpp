struct Node {
    Node* links[26];
    int sum = 0;

    Node* get(char c) {
        return links[c - 'a'];
    }

    void put(char c, Node* newNode) {
        links[c - 'a'] = newNode;
    }

    void setSum(int n) {
        sum += n;
    }

    int getSum() {
        return sum;
    }
};

class MapSum {
    private:
    Node* root ;
    unordered_map<string, int> keyval;
public:
    MapSum() {
        root = new Node();
    }
    
    void insert(string key, int val) {
        Node* node = root;
        int valToInsert = val - keyval[key];
        keyval[key] = val;

        for(int i = 0; i < key.size(); i++) {
            if(!node->get(key[i])) {
                node->put(key[i], new Node());
            }
            node = node->get(key[i]);
            node->setSum(valToInsert);
        }
    }
    
    int sum(string prefix) {
        Node* node = root;


        for(int i = 0; i < prefix.size(); i++) {
            if(!node->get(prefix[i]) && i < prefix.size()) {
                return 0;
            }

            else if(!node->get(prefix[i])) {
                return node->getSum();
            }
            node = node->get(prefix[i]);
        }

        return node->getSum();
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */