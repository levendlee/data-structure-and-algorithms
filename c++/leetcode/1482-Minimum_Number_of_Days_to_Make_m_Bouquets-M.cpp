class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        const int max_days = *std::max_element(bloomDay.begin(), bloomDay.end());
        const int min_days = *std::min_element(bloomDay.begin(), bloomDay.end());
        int lo = min_days;
        int hi = max_days;
        //const int n = bloomDay.size();
        int res = hi + 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int bunch = 0, count = 0;
            for (const auto& d : bloomDay) {
                if (d <= mid) {
                    bunch++;
                } else {
                    count += bunch / k;
                    bunch = 0;
                }
            }

            count += bunch / k;
            if (count >= m) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return res <= max_days ? res : -1;
    }
};