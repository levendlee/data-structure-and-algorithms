// 857 Minimum Cost to Hire K Workers
// https://leetcode.com/problems/minimum-cost-to-hire-k-workers

// version: 1; create time: 2020-02-16 21:58:43;
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        const int n = wage.size();

        vector<int> order(n, 0);
        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(),
             [&](const auto& l, const auto& r) { return (1.0*wage[l])/quality[l] < (1.0*wage[r])/quality[r]; });

        double mincost = -1;

        int quality_sum = 0;
        priority_queue<int> pq;
        for (int i = 0; i < n; ++i) {
            auto idx = order[i];
            pq.push(quality[idx]);
            quality_sum += quality[idx];
            if (pq.size() > K) {
                quality_sum -= pq.top(); pq.pop();
            }
            if (i >= K - 1) {
                double cost = ((1.0*wage[idx])/quality[idx]) * quality_sum;
                if (mincost < 0 || cost < mincost) {
                    mincost = cost;
                }
            }
        }

        return mincost;
    }
};
