class Solution {
public:

    string encode(vector<string>& strs) {
        auto sz = strs.size();
        std::string szs;
        std::string payload;
        for (const auto& s : strs) {
            szs += std::to_string(s.size()) + " ";
            payload += s;
        }
        std::string prefix{std::to_string(sz) + " " + szs};
        std::cout << prefix + payload << "\n";
        return prefix + payload;
    }

    vector<string> decode(string s) {
        int i = 0;
        std::string numStrings;
        while(s[i] != ' ') {
            numStrings += s[i];
            ++i;
        }
        int sz = std::stoi(numStrings);
        // std::cout << "size " << sz << "\n";
        std::vector<int> sizes;
        ++i;
        for (int j = 0; j < sz; ++j) {
            int start = i;
            std::string num;
            while (s[i] != ' ') {
                num += s[i];
                ++i;
            }
            sizes.push_back(std::stoi(num));
            // std::cout << "index " << j << " size " << num << std::endl;
            ++i;
        }
        vector<string> result;
        for (const auto& k: sizes) {
            int start = 0;
            std::string r;
            while (start < k) {
                r += s[i];
                ++i;
                ++start;
            }
            result.push_back(r);
        }
        return result;
    }
};
