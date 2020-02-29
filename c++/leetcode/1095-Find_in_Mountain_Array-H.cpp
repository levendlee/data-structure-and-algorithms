// 1095 Find in Mountain Array
// https://leetcode.com/problems/find-in-mountain-array

// version: 1; create time: 2020-01-29 21:26:13;
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        unordered_map<int, int> cache;
        const auto get_elem = [&](int idx) {
            if (cache.count(idx)) {
                return cache[idx];
            } else {
                return cache[idx] = arr.get(idx);
            }
        };

        const int n = arr.length();
        int lo = 1, hi = n - 1;
        while (lo < hi) {
            const auto mid = lo + (hi - lo) / 2;
            if (get_elem(mid) < get_elem(mid + 1)) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        const int peak = lo;
        lo = 0, hi = peak;
        while (lo <= hi) {
            const auto mid = lo + (hi - lo) / 2;
            const auto elem = get_elem(mid);
            if (elem > target) {
                hi = mid - 1;
            } else if (elem < target) {
                lo = mid + 1;
            } else {
                return mid;
            }
        }

        lo = peak, hi = n - 1;
        while (lo <= hi) {
            const auto mid = lo + (hi - lo) / 2;
            const auto elem = get_elem(mid);
            if (elem < target) {
                hi = mid - 1;
            } else if (elem > target) {
                lo = mid + 1;
            } else {
                return mid;
            }
        }

        return -1;
    }
};
