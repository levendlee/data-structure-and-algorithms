class Solution {
public:
    // divide and conquer solution
    vector<vector<int>> mergeSkyline(vector<vector<int>>& buildings, int lo, int hi) {
        if (lo > hi) return {};
        if (lo == hi) return {{buildings[lo][0], buildings[lo][2]}, {buildings[lo][1], 0}};

        int mid = lo + (hi - lo) / 2;
        const auto lsky = mergeSkyline(buildings, lo, mid);
        const auto rsky = mergeSkyline(buildings, mid + 1, hi);
        const auto lsize = lsky.size(), rsize = rsky.size();
        int i = 0, j = 0;

        vector<vector<int>> res;
        int cur_h = 0, lh = 0, rh = 0;

        auto update_res = [&](int start) {
            auto nex_h = max(lh, rh);
            if (nex_h != cur_h) {
                cur_h = nex_h;
                if (!res.empty() && res.back()[0] == start) {
                    res.back()[1] = cur_h;
                } else {
                    res.push_back({start, cur_h});
                }
            }
        };

        while (i < lsize || j < rsize) {
            if (j == rsize || i < lsize && lsky[i][0] < rsky[j][0]) {
                lh = lsky[i][1];
                update_res(lsky[i][0]);
                ++i;
            } else {
                rh = rsky[j][1];
                update_res(rsky[j][0]);
                ++j;
            }
        }

        return res;
    }

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.empty()) return {};
        return mergeSkyline(buildings, 0, buildings.size() - 1);
    }
};