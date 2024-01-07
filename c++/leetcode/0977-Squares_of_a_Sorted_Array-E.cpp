// 977 Squares of a Sorted Array
// https://leetcode.com/problems/squares-of-a-sorted-array

// version: 1; create time: 2020-02-01 20:42:27;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        const int n = A.size();
        if (n == 0) return {};

        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (A[mid] < 0) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        vector<int> res;
        int i = lo, j = lo - 1;
        while (i < n || j >= 0) {
            if (j < 0 || i < n && A[i] < -A[j]) {
                res.push_back(A[i] * A[i]); ++i;
            } else {
                res.push_back(A[j] * A[j]); --j;
            }
        }
        return res;
    }
};

//

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        const int n = nums.size();
        int j = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int i = j - 1;
        vector<int> res;
        while (i >= 0 || j < n) {
            if (i < 0 || j < n && (nums[j] < -nums[i])) {
                res.push_back(nums[j] * nums[j]);
                ++j;
            } else {
                res.push_back(nums[i] * nums[i]);
                --i;
            }
        }
        return res;
    }
};