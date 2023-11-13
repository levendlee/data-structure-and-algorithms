class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        const int n = piles.size();

        int lo = 1, hi = *max_element(piles.begin(), piles.end());
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int hours = 0;
            for (int p : piles) {
                hours += ((p - 1) / mid) + 1;
            }
            if (hours > h) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        return lo;
    }
};
