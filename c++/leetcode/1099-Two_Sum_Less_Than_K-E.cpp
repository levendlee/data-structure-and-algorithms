// 1099 Two Sum Less Than K
// https://leetcode.com/problems/two-sum-less-than-k

// version: 1; create time: 2019-12-30 15:02:40;
class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        int S = INT_MIN;
        set<int> bst;
        for (const auto& a : A) {
            auto iter = bst.lower_bound(K - a);
            if (iter != bst.begin()) {
                --iter;
                S = std::max(S, a + *iter);
            }
            bst.insert(a);
        }
        return S == INT_MIN ? -1 : S;
    }
};
