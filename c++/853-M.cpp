class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        const int n = position.size();
        if (n <= 1) return n;

        vector<int> order(n, 0);
        std::iota(order.begin(), order.end(), 0);
        std::sort(order.begin(), order.end(), [&](const auto& l, const auto& r) { return position[l] > position[r]; });

        vector<float> time(n);
        for (int i = 0; i < n; ++i) {
            time[i] = 1.0 * (target - position[order[i]]) / speed[order[i]];
        }

        int fleet = 1;
        float bottleneck = time[0];
        for (int i = 1; i < n; ++i) {
            if (time[i] > bottleneck) {
                bottleneck = time[i];
                ++fleet;
            }
        }

        return fleet;
    }
};