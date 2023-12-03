class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        const int n = arr.size();

        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            int missing = arr[mid] - mid - 1;
            if (missing >= k) {
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }
        int missing = arr[lo] - lo - 1;
        // missing <= k
        if (missing < k) {
            return arr[lo] + (k - missing);
        }
        return k;

    }
};
