// 1320 Minimum Distance to Type a Word Using Two Fingers
// https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers

// version: 1; create time: 2020-01-29 22:20:24;
class Solution {
public:
    int minimumDistance(string word) {
        unordered_map<string, int> dp;
        dp["##"] = 0;

        const auto calc_dist = [](const char c1, const char c2) {
            if (c1 == '#' || c2 == '#') return 0;
            const int idx1 = c1 - 'A';
            const int idx2 = c2 - 'A';
            return abs(idx1 / 6 - idx2 / 6) + abs(idx1 % 6 - idx2 % 6);
        };

        for (const auto c : word) {
            unordered_map<string, int> ndp;
            for (const auto& p : dp) {
                const auto s = p.first;
                auto tmp1 = string(1, c) + s[1];
                auto dist1 = calc_dist(s[0], c) + p.second;
                if (ndp.count(tmp1)) {
                    ndp[tmp1] = std::min(ndp[tmp1], dist1);
                } else {
                    ndp[tmp1] = dist1;
                }
                auto tmp2 = s[0] + string(1, c);
                auto dist2 = calc_dist(s[1], c) + p.second;
                if (ndp.count(tmp2)) {
                    ndp[tmp2] = std::min(ndp[tmp2], dist2);
                } else {
                    ndp[tmp2] = dist2;
                }
            }
            dp = std::move(ndp);
        }

        int min_dist = INT_MAX;
        for (const auto& p : dp) {
            min_dist = std::min(min_dist, p.second);
        }
        return min_dist;
    }
};
