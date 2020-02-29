// 349 Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays

// version: 1; create time: 2020-02-05 22:22:28;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> num_set;
        for (const auto& n : nums1) {
            num_set.insert(n);
        }
        vector<int> res;
        for (const auto& n : nums2) {
            if (num_set.count(n)) {
                res.push_back(n);
                num_set.erase(n);
            }
        }
        return res;
    }
};
