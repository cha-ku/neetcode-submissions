class LRUCache {
    unordered_map<int, int> data;
    unordered_map<int, int> counts;
    int cap = 0;
    int tick = 0;
public:
    LRUCache(int capacity): cap(capacity) {
    }
    
    int get(int key) {
        if (!data.contains(key)) {
            return -1;
        }
        ++tick;
        counts[key] = tick;
        return data[key];
    }
    
    void put(int key, int value) {
        data[key] = value;
        ++tick;
        counts[key] = tick;
        if (data.size() > cap) {
            int min_count = INT_MAX;
            int min_key = -1;
            for (auto [k, v] : counts) {
                if (v < min_count) {
                    min_key = k;
                    min_count = v;
                }
            }
            counts.erase(min_key);
            data.erase(min_key);
        }
    }
};
