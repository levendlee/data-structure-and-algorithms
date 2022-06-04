class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        std::sort(rectangles.begin(), rectangles.end());
        std::vector<int> point_index(points.size());
        std::iota(point_index.begin(), point_index.end(), 0);
        std::sort(point_index.begin(), point_index.end(), [&](auto i, auto j) { return points[i] < points[j]; });
        std::vector<int> histo(101);
        int i = rectangles.size() - 1, j = points.size() - 1;
        std::vector<int> res_vec(points.size());
        while (j >=0) {
            if (i >= 0 && rectangles[i][0] >= points[point_index[j]][0]) {
                histo[rectangles[i][1]]++;
                i--;
            } else {
                int res = 0;
                for (int k = points[point_index[j]][1]; k <= 100; ++k) {
                    res += histo[k];
                }
                res_vec[point_index[j]] = res;
                j--;
            }
        }
        return res_vec;
    }
};
