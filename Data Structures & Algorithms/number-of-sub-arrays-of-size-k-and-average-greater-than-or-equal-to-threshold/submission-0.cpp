class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int result = 0;
        for (int i = 0; i < arr.size(); ++i) {
            int sum = 0;
            int l = i;
            int r = l + k;
            if (r > arr.size()) {
                break;
            }
            while (l < r) {
                sum += arr[l];
                ++l;
            }
            if (sum >= k * threshold) {
                ++result;
            }
            sum -= arr[i];
        }
        return result;
        
    }
};