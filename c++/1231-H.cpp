class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {
        int64_t min_element = *std::min_element(sweetness.begin(), sweetness.end());
        int64_t lo = min_element;
        int64_t hi = std::accumulate(sweetness.begin(), sweetness.end(), int64_t(0));
        int64_t max_sweetness = 0;
        while (lo < hi) {
            int64_t mid = lo + (hi - lo) / 2;
            int64_t cur = 0;
            int cnt = 0;
            int64_t local_min_sweetness = INT_MAX;
            for (auto& s : sweetness) {
                cur += s;
                if (cur >= mid) {
                    local_min_sweetness = std::min(local_min_sweetness, cur);
                    cur = 0;
                    ++cnt;
                }
            }
            if (cnt >= K + 1) {
                max_sweetness = std::max(max_sweetness, local_min_sweetness);
            }
            if (cnt >= K + 1) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return max_sweetness;
    }
};