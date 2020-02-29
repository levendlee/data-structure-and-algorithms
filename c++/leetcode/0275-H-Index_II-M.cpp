// 275 H-Index II
// https://leetcode.com/problems/h-index-ii

// version: 1; create time: 2020-02-02 14:42:14;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        const int n = citations.size();
        if (n == 0) return 0;

        int lo = 0, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (citations[mid] >= n - mid) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return n - lo;
    }
};
