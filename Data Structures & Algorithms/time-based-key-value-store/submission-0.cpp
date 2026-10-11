class TimeMap {
    unordered_map<string, vector<pair<int, string>>> key_timestamp_vals;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        key_timestamp_vals[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if (!key_timestamp_vals.contains(key)) {
            return {};
        }
        const auto& r = key_timestamp_vals[key];
        int left = 0;
        int right = r.size()-1;
        string result;
        while (left <= right) {
            int mid = left + (right - left)/2;
            int ts = r[mid].first;
            if (ts <= timestamp) {
                result = r[mid].second;
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        return result;
    }
};
