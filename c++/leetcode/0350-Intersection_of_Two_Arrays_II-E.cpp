// 350 Intersection of Two Arrays II
// https://leetcode.com/problems/intersection-of-two-arrays-ii

// version: 1; create time: 2020-02-07 21:32:40;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> cnt1;
        for (const auto& n : nums1) {
            ++cnt1[n];
        }
        for (const auto& n : nums2) {
            if (cnt1.count(n)) {
                if (--cnt1[n] == 0) {
                    cnt1.erase(n);
                }
                res.push_back(n);
            }
        }
        /*
        vector<int> res;
        const int n1 = nums1.size();
        const int n2 = nums2.size();
        if (n1 == 0 || n2 == 0) return res;

        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (nums1[i] > nums2[j]) {
                ++j;
            }
            else if (nums1[i] < nums2[j]) {
                ++i;
            }
            else {
                res.push_back(nums1[i]);
                ++i; ++j;
            }
        }
        */
        return res;
    }
};
