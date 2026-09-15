class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // vector<float> times(position.size());
        // for (int i = 0; i < times.size(); ++i) {
        //     times[i] = static_cast<float>(target-position[i])/speed[i];
        // }
        vector<pair<int, int>> combined;
        for (int i = 0; i < position.size(); ++i) {
            combined.push_back(std::make_pair(position[i], speed[i]));
        }

        std::sort(combined.begin(), combined.end(), [](const pair<int, int>& c1, const pair<int, int>& c2) {
            return c1.first < c2.first;
        });

        stack<float> times;

        for (int i = combined.size()-1; i > -1; --i) {
            const auto& [pos, spd] = combined[i];
            float time = static_cast<float>(target - pos)/spd;
            if (times.empty() || times.top() < time) {
                times.push(time);
                continue;
            }
        }

        return times.size();
        
    }
};
