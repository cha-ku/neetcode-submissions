class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[rows-1][cols-1]) {
            return false;
        }
        int row = rows - 1;
        if (rows > 1) {
            for (int i = 1; i < rows; ++i) {
                if (target == matrix[i][0]) {
                    return true;
                }
                if (target < matrix[i][0] && target >= matrix[i-1][0]) {
                    row = i-1;
                    break;
                }
            }
        }
        // std::cout << row << "\n";
        int l = 0;
        int r = cols-1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (target == matrix[row][mid]) {
                return true;
            }
            if (target < matrix[row][mid]) {
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return false;
    }
};
