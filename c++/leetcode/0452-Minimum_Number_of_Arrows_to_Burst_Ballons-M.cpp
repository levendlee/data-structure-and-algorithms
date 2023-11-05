class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
            [](const auto& p0, const auto& p1) { return p0[1] < p1[1]; });

        int num_arrows = 0, shoot = -1;
        for (const auto& p : points) {
            if (num_arrows == 0 || shoot < p[0]) {
                ++num_arrows;
                shoot = p[1];
            }
        }

        return num_arrows;
    }
};
