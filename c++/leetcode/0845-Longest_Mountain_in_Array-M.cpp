// 845 Longest Mountain in Array
// https://leetcode.com/problems/longest-mountain-in-array

// version: 1; create time: 2020-02-02 15:16:33;
class Solution {
public:
    int longestMountain(vector<int>& A) {
        const int n = A.size();
        int dec = INT_MAX, inc = INT_MIN;
        int longest = 0;
        for (int i = 1; i < n; ++i) {
            if (A[i-1] < A[i]) {
                if (inc > dec) {
                    dec = INT_MAX;
                }
                dec = std::min(dec, i - 1);
            } else if (A[i-1] > A[i]) {
                inc = std::max(inc, i);
                if (dec < inc) {
                    longest = std::max(longest, inc - dec + 1);
                }
            } else {
                dec = INT_MAX;
                inc = INT_MIN;
            }
        }
        return longest;
    }
};
