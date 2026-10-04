class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();
        unordered_map<char, int> counts;
        for (const auto& c : tasks) {
            counts[c]++;
        }
        auto cmp = [](const pair<char, int>& p1, const pair<char, int>& p2) {
            return p1.second < p2.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq;
        for (const auto& [k, v]: counts) {
            pq.push({k, v});
        }
        int result = 0;
        while (!counts.empty()) {
            auto [task, count] = pq.top();
            result++;
            // std::cout << task << ", " << count << "\n";
            pq.pop();
            if (count == 1) {
                counts.erase(task);
            }
            else {
                counts[task]--;
            }
            if (counts.empty()) return result;
            int wait = n;
            while (wait > 0) {
                while (!pq.empty() && wait > 0) {
                    auto [k, v] = pq.top();
                    // std::cout << k << ",  " << v << "\n";
                    if (v == 1) {
                        counts.erase(k);
                    }
                    else {
                        counts[k]--;
                    }
                    pq.pop();
                    result++;
                    if (counts.empty()) return result;
                    wait--;
                }
                while (wait > 0 && pq.empty()) {
                    wait--;
                    result++;
                    // std::cout << "idle\n";
                }
            }
            pq = priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)>();
            for (const auto& [k, v]: counts) {
                pq.push({k, v});
            }

        }
        return result; 
    }
};
