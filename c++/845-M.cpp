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