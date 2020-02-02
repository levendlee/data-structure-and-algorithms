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