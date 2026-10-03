class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        for (const auto& a : asteroids) {
            bool destroyed = false;
            while (!s.empty() && a < 0 && s.back() > 0) {
                if (s.back() < -a) {
                    s.pop_back();
                    continue;
                } else if (s.back() == -a) {
                    s.pop_back();
                }
                destroyed = true;
                break;
            }
            if (!destroyed) {
                s.push_back(a);
            }
        }
        return s;
    }
};