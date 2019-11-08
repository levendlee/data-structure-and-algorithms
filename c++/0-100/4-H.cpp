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