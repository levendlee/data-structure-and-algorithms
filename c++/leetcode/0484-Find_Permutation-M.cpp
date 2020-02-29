// 484 Find Permutation
// https://leetcode.com/problems/find-permutation

// version: 1; create time: 2020-02-04 20:53:18;
class Solution {
public:
    vector<int> findPermutation(string s) {
        const int n = s.size();

        vector<int> res(n + 1, 0);
        std::iota(res.begin(), res.end(), 1);

        int i = 0, j = 0;
        while (j < n) {
            if (s[j] == 'D') {
                i = j;
                while (j < n && s[j] == 'D') ++j;
                // [i, ..., j] should be decreasing
                std::reverse(res.begin() + i, res.begin() + j + 1);
            } else {
                ++j;
            }
        }

        return res;
    }
};
