// 1122 Relative Sort Array
// https://leetcode.com/problems/relative-sort-array

// version: 1; create time: 2020-02-01 15:17:29;
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> indexer2;
        const int n2 = arr2.size();
        for (int i = 0; i < n2; ++i) {
            indexer2[arr2[i]] = i;
        }
        std::sort(arr1.begin(), arr1.end(),
                 [&](const auto& l, const auto& r) {
                     bool has_l = indexer2.count(l);
                     bool has_r = indexer2.count(r);
                     if (!has_l && !has_r) return l < r;
                     if (!has_l) return false;
                     if (!has_r) return true;
                     return indexer2[l] < indexer2[r];
                 });
        return arr1;
    }
};
