class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int maxResult = 0;
        while (left < right) {
            int height = std::min(heights[left], heights[right]) * (right - left);
            maxResult = height > maxResult ? height : maxResult;
            heights[left] < heights[right] ? ++left : --right;
        }
        return maxResult;
    }
};
