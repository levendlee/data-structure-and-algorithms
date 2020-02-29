// 962 Maximum Width Ramp
// https://leetcode.com/problems/maximum-width-ramp

// version: 1; create time: 2020-01-25 23:01:20;
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        const int n = A.size();
        int max_w = 0;

        // O(NlogN)
        /*
        std::vector<int> dec;
        for (int j = 0; j < n; ++j) {
            const auto it = std::lower_bound(dec.begin(), dec.end(), j,
                                             [&](const auto& l, const auto& r) { return A[l] > A[r]; });
            if (it != dec.end()) {
                max_w = std::max(max_w, j - *it);
            }
            if (dec.empty() || A[j] < A[dec.back()]) {
                dec.push_back(j);
            }
        }
        */

        std::stack<int> dec;
        for (int j = 0; j < n; ++j) {
            if (dec.empty() || A[j] < A[dec.top()]) {
                dec.push(j);
            }
        }

        for (int j = n - 1; j >= 0; --j) {
            while (!dec.empty() && A[j] >= A[dec.top()]) {
                max_w = std::max(max_w, j - dec.top()); dec.pop();
            }
        }
        return max_w;
    }
};
