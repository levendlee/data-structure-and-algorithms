// 875 Koko Eating Bananas
// https://leetcode.com/problems/koko-eating-bananas

// version: 1; create time: 2020-02-10 14:14:15;
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
