// 88 Merge Sorted Array
// https://leetcode.com/problems/merge-sorted-array

// version: 1; create time: 2020-02-01 20:12:31;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = 0, idx = m + n - 1;
        std::reverse(nums1.begin(), nums1.begin() + m);
        while (i >= 0 || j < n) {
            if (i < 0 || j < n && nums2[j] < nums1[i]) {
                nums1[idx--] = nums2[j++];
            } else {
                nums1[idx--] = nums1[i--];
            }
        }
        std::reverse(nums1.begin(), nums1.end());
    }
};
