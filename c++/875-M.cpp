class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int lo = 1, hi = *max_element(piles.begin(), piles.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int cnt = 0;
            for (const auto& p : piles) {
                cnt += (p - 1) / mid + 1;
            }
            if (cnt > H) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};