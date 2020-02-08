class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        std::sort(points.begin(), points.end());
        int cnt = 1;
        int arrow = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > arrow) {
                cnt++;
                arrow = points[i][1];
            } else {
                arrow = std::min(arrow, points[i][1]);
            }
        }
        return cnt;
    }
};