class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res;
        unordered_set<int> set1, set2, nset1, nset2;
        for (int n : nums1) {
            set1.insert(n);
        }
        for (int n : nums2) {
            set2.insert(n);
        }
        for (int n : set1) {
            if (!set2.count(n)) nset1.insert(n);
        }
        for (int n : set2) {
            if (!set1.count(n)) nset2.insert(n);
        }
        res.emplace_back(nset1.begin(), nset1.end());
        res.emplace_back(nset2.begin(), nset2.end());
        return res;
    }
};
