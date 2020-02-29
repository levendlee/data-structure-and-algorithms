// 218 The Skyline Problem
// https://leetcode.com/problems/the-skyline-problem

// version: 1; create time: 2020-02-16 14:29:23;
class Solution {
public:
    // priority queue solution
    // greedy
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        sort(buildings.begin(), buildings.end());

        vector<vector<int>> res;        // {points, height}
        priority_queue<vector<int>> pq; // {height, endpoint}

        auto update_ends = [&](long cutoff) {
            // popped all the buildings that cannot have overlap with the next building
            while (!pq.empty() && pq.top()[1] < cutoff) {
                int end = pq.top()[1]; pq.pop();
                // find the next skyline height when the current highest building is popped out
                while (!pq.empty() && pq.top()[1] <= end) {
                    pq.pop();
                }
                int cur_h = res.empty() ? 0 : res.back()[1];
                int nex_h = pq.empty() ? 0 : pq.top()[0];
                // update the next skyline height it is smaller thant the current height
                if (nex_h < cur_h) {
                    res.push_back({end, nex_h});
                }
            }
        };

        auto update_starts = [&](int start, int end, int height) {
            int cur_h = pq.empty() ? 0 : pq.top()[0];
            // update the skyline height
            if (height > cur_h) {
                if (!res.empty() && res.back()[0] == start) {
                    res.back()[1] = height;
                } else {
                    res.push_back({start, height});
                }
            }
            // put this building int the priority queue
            pq.push({height, end});
        };

        for (const auto& build : buildings) {
            update_ends(build[0]);
            update_starts(build[0], build[1], build[2]);
        }
        update_ends(INT_MAX + 1L);

        return res;
    }
};


// version: 2; create time: 2020-02-16 14:46:22;
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
