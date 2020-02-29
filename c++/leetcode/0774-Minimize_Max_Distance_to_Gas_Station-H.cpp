// 774 Minimize Max Distance to Gas Station
// https://leetcode.com/problems/minimize-max-distance-to-gas-station

// version: 1; create time: 2019-12-25 15:27:31;
class Solution {
private:
    struct Range
    {
        int size;
        int stops;

        double dist() const {
            return size / (stops + 1.0);
        }
        bool operator<(const Range& rhs) const {
            return dist() < rhs.dist();
        }
    };

public:
    double minmaxGasDist(vector<int>& stations, int K) {
        const int n = stations.size();

        // Two methods. Binary search is better because N is smaller than K.

        /*
        // Priorty Queue -> Time Limit
        // Time Complexity O(KlogN)
        std::priority_queue<Range> pq;
        for (int i = 1; i < n; ++i) {
            Range rng = {stations[i] - stations[i-1], 0};
            pq.push(rng);
        }


        while (K) {
            auto top1 = pq.top(); pq.pop();
            const auto top2 = pq.top();
            // Divide the top1 until it is smaller than top2
            int cuts = std::ceil((top1.dist() / top2.dist()) * (top1.stops + 1));
            // At least add 1 stations; At most add all stations left
            cuts = std::min(std::max(cuts, top1.stops + 2), top1.stops + 1 + K);
            K -= cuts - 1 - top1.stops;
            top1.stops = cuts - 1;
            pq.push(top1);
        }

        return pq.top().dist();
        */

        // Binary Search
        // Time Complexity O(NlogD)
        // D is the maximum distance
        double max_dist = INT_MIN, min_dist = INT_MAX;
        for (int i = 1; i < n; ++i) {
            double dist = stations[i] - stations[i-1];
            max_dist = std::max(max_dist, dist);
            min_dist = std::min(min_dist, dist);
        }

        constexpr double limit = pow(10, -6);
        double lo = 0, hi = max_dist;
        while ((hi - lo) > limit) {
            double mid = (lo + hi) / 2.0;
            int cnt = 0;
            for (int i = 1; i < n; ++i) {
                double dist = stations[i] - stations[i-1];
                cnt += std::ceil(dist / mid) - 1;
            }
            if (cnt <= K) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        return lo;
    }
};
