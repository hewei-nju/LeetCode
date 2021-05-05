class LRUCache {
public:
    LRUCache(int capacity) {

    }
    
    int get(int key) {
        auto find = hashMap.find(key);
        if (find != hashMap.end()) {
            cache.
            return find->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto find = 
    }

private:
    std::queue<std::pair<int, int>> cache;
    std::unordered_map<int, int> hashMap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */