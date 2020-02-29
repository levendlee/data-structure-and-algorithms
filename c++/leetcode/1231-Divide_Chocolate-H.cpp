// 1231 Divide Chocolate
// https://leetcode.com/problems/divide-chocolate

// version: 2; create time: 2020-02-16 17:22:17;
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


// version: 1; create time: 2019-11-06 21:35:21;
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
