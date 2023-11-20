// 1011 Capacity To Ship Packages Within D Days
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

// version: 1; create time: 2019-10-27 12:02:14;
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int64_t lo = *std::max_element(weights.begin(), weights.end());
        int64_t hi = std::accumulate(weights.begin(), weights.end(), static_cast<int64_t>(0));
        int min_capacity = 0;
        while (lo < hi) {
            int64_t mid = lo + (hi - lo) / 2;
            int64_t sum = 0;
            int n_packages = 1;
            for (const auto& w : weights) {
                sum += w;
                if (sum > mid) {
                    ++n_packages;
                    sum = w;
                }
            }
            if (n_packages > D) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        return lo;
    }
};

//

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int num_days = 0;
            int total_weight = 0;
            for (int w : weights) {
                if (total_weight + w > mid) {
                    total_weight = w;
                    ++num_days;
                } else {
                    total_weight += w;
                }
            }
            ++num_days;

            if (num_days > days) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};
