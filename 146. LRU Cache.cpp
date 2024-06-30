class LRUCache {
public:
    map<int, int> LRUMap;
    queue<int> history;
    map<int, int> counter;
    int capacity;

    LRUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        if(counter[key]) {
            counter[key]++;
            history.push(key);
            return LRUMap[key];
        }
        return -1;
    }

    void remove() {
        while (!history.empty()) {
            int curr = history.front();
            history.pop();
            counter[curr]--;
            if (counter[curr] == 0) {
                LRUMap.erase(curr);
                break;
            }
        }
    }

    void put(int key, int value) {

        LRUMap[key] = value;
        counter[key] ? counter[key] ++ : counter[key] = 1;
        history.push(key);
        if (LRUMap.size() > this->capacity)
            remove();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */