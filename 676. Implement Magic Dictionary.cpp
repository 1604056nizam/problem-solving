struct Node {

    Node* links[26];
    bool isEnd = false;

    Node* get(char c) { return links[c - 'a']; }

    void put(char c, Node* newNode) { links[c - 'a'] = newNode; }

    void setEnd() { isEnd = true; }

    bool getEnd() { return isEnd; }
};

class MagicDictionary {

private:
    Node* root;

public:
    MagicDictionary() { root = new Node(); }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->get(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    void buildDict(vector<string> dictionary) {
        for (int i = 0; i < dictionary.size(); i++) {
            insert(dictionary[i]);
        }
    }

    bool dfs(Node* node, string& searchWord, int index, bool modified) {
        if(index == searchWord.size()) {
            return modified && node->getEnd();
        }

        if(node->get(searchWord[index])) {
            if(dfs(node->get(searchWord[index]), searchWord, index+ 1, modified)) {
                return true;
            }
        }

        if(!modified) {
            for(char c = 'a'; c <= 'z'; c++) {
                if(c != searchWord[index] && node->get(c)) {
                    if(dfs(node->get(c), searchWord, index + 1, true)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool search(string searchWord) {
        return dfs(root, searchWord, 0, false);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */