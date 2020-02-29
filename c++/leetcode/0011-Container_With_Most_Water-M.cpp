// 11 Container With Most Water
// https://leetcode.com/problems/container-with-most-water

// version: 1; create time: 2020-01-19 16:36:48;
class Solution {
public:
    int maxArea(vector<int>& height) {
        const int n = height.size();
        if (n <= 1) return 0;

        int i = 0, j = n - 1;
        int max_area = 0;
        while (i < j) {
            const auto h = std::min(height[i], height[j]);
            max_area = std::max(max_area, h * (j - i));
            if (height[i] < height[j]) {
                while (i < j && height[i] <= h) ++i;
            } else {
                while (i < j && height[j] <= h) --j;
            }
        }
        return max_area;
    }
};
