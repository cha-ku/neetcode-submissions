class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> combined;
        for (int i = 0; i < position.size(); ++i) {
            combined.push_back(std::make_pair(position[i], speed[i]));
        }

        std::sort(combined.begin(), combined.end(), [](const pair<int, int>& c1, const pair<int, int>& c2) {
            return c1.first < c2.first;
        });

        int fleets = 0;
        double slowest = 0.0;
        for (int i = combined.size()-1; i > -1; --i) {
            const auto& [pos, spd] = combined[i];
            double time = static_cast<double>(target - pos)/spd;
            if (time > slowest) {
                ++fleets;
                slowest = time;
            }
        }

        return fleets;
        
    }
};