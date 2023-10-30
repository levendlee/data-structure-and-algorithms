// 4 Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays

// version: 1; create time: 2019-11-07 21:50:14;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const size_t m = nums1.size();
        const size_t n = nums2.size();

        if (m < n) {
            return findHelper(nums1, nums2);
        } else {
            return findHelper(nums2, nums1);
        }
    }

    double findHelper(const vector<int>& nums1, const vector<int>& nums2) {
        const size_t m = nums1.size();
        const size_t n = nums2.size();

        size_t h = (m + n) / 2;
        size_t lo = 0, hi = m;

        while (lo <= hi) {
            size_t mid1 = (lo + hi) / 2;
            size_t mid2 = h - mid1;

            int l1 = mid1 > 0 ? nums1[mid1-1] : INT_MIN;
            int l2 = mid2 > 0 ? nums2[mid2-1] : INT_MIN;
            int left_max = std::max(l1, l2);

            int r1 = mid1 < m ? nums1[mid1] : INT_MAX;
            int r2 = mid2 < n ? nums2[mid2] : INT_MAX;
            int right_min = std::min(r1, r2);

            if (left_max <= right_min) {
                return (m + n) % 2 ? right_min : (left_max + right_min) / 2.0;
            }

            if (l1 < l2) {
                lo = mid1 + 1;
            } else {
                hi = mid1 - 1;
            }
        }
        return 0;
    }
};

// 2023/10/29

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2) {
            return findMedianSortedArrays(nums2, nums1);
        }

        const int half = (n1 + n2) / 2;
        const bool odd = (n1 + n2) % 2;

        int lo = 0, hi = n1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int idx1 = mid;
            int idx2 = half - mid;
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

            if (idx1 > 0) {
                l1 = nums1[idx1 - 1];
            }
            if (idx2 > 0) {
                l2 = nums2[idx2 - 1];
            }
            if (idx1 < n1) {
                r1 = nums1[idx1];
            }
            if (idx2 < n2) {
                r2 = nums2[idx2];
            }
            if (l1 <= r2 && l2 <= r1) {
                if (odd) {
                    return std::min(r1, r2);
                } else {
                    return (std::max(l1, l2) + std::min(r1, r2)) / 2.0;
                }
            } else if (l1 > r2) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return 0.0;
    }
};
