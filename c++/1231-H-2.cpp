class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {
        long lo = *min_element(sweetness.begin(), sweetness.end());
        long hi = accumulate(sweetness.begin(), sweetness.end(), long(0));
        if (K == 0) return hi;

        int res = 0;
        while (lo < hi) {
            auto mid = lo + (hi - lo) / 2;
            int cnt = 0, sum = 0, min_sweet = INT_MAX;
            for (const auto& s : sweetness) {
                sum += s;
                if (sum >= mid) {
                    min_sweet = min(min_sweet, sum);
                    sum = 0;
                    ++cnt;
                }
            }
            if (cnt >= K + 1) {
                res = std::max(min_sweet, res);
            }
            if (cnt >= K + 1) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        return res;
    }
};