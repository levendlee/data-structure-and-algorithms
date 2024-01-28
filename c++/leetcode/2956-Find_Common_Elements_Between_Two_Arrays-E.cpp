class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count1, count2;
        for (int n : nums1) {
            ++count1[n];
        }
        for (int n : nums2) {
            ++count2[n];
        }
        vector<int> res(2, 0);
        for (auto [n, cnt] : count1) {
            res[0] += cnt * count2.count(n);
        }
        for (auto [n, cnt] : count2) {
            res[1] += cnt * count1.count(n);
        }
        return res;
    }
};