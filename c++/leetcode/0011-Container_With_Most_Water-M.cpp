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

// 2023/09/28

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        const int n = height.size();
        int i = 0, j = n - 1;
        while (i < j) {
            max_area = std::max(max_area, (j - i) * std::min(height[i], height[j]));
            if (height[i] > height[j]) {
                --j;
            } else {
                ++i;
            }
        }
        return max_area;
    }
};
