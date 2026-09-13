class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        std::stack<int> indices;
        for(int i = 0; i < temperatures.size(); ++i) {
            int temp = temperatures[i];
            while (!indices.empty() && temperatures[indices.top()] < temp) {
                result[indices.top()] = i - indices.top();
                indices.pop();
            }
            indices.push(i);
        }
        return result;
    }
};
