// 360 Sort Transformed Array
// https://leetcode.com/problems/sort-transformed-array

// version: 1; create time: 2019-12-18 21:11:18;
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        const int n = nums.size();
        // 1) quadratic
        int i;
        int j;
        int i_inc = -1;
        int j_inc = 1;
        if (a > 0) {
            int center = -b / (2 * a);
            j = std::lower_bound(nums.begin(), nums.end(), center) - nums.begin();
            i = j - 1;
        } else if (a < 0) {
            int center = b / (2 * a);
            i = 0;
            j = n - 1;
            i_inc = 1;
            j_inc = -1;
        } else if (b > 0) {
            i = -1;
            j = 0;
        } else if (b < 0) {
            i = n - 1;
            j = n;
        } else {
            return vector<int>(n, c);
        }

        auto calc = [&](int x) { return a*x*x + b*x + c; };

        vector<int> res;
        while ((i >= 0 || j < n) && (i <= j)) {
            int left = i >= 0 ? calc(nums[i]) : INT_MAX;
            int right = j < n ? calc(nums[j]) : INT_MAX;
            if (left <= right) {
                res.push_back(left);
                i += i_inc;
            } else {
                res.push_back(right);
                j += j_inc;
            }
        }
        return res;
    }
};
