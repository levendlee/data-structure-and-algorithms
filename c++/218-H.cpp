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