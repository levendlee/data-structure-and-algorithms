class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        /*
        // Sorts flowers based on starting date.
        // O(Mlog(M))
        sort(flowers.begin(), flowers.end());

        // Creates day to num of blooms mapping.
        // O(Nlog(N))
        unordered_map<int, int> days_map;
        for (int d : people) {
            days_map[d] = 0;
        }
        // Sorts unique days.
        vector<int> days_vec;
        for (const auto& [day, cnt] : days_map) {
            days_vec.push_back(day);
        }
        sort(days_vec.begin(), days_vec.end());

        // In order traverse unique days.
        // For each day, update the flowers that start to bloom and end from blooming.
        const int m = flowers.size(), n = days_vec.size();
        priority_queue<int> bloom_endings;
        int i = 0, j = 0;
        // O(Nlog(M))
        while (j < n) {
            int day = days_vec[j];
            while (i < m && flowers[i][0] <= day) {
                bloom_endings.push(-flowers[i++][1]);
            }
            while (!bloom_endings.empty() && -bloom_endings.top() < day) {
                bloom_endings.pop();
            }
            days_map[day] = bloom_endings.size();
            ++j;
        }

        vector<int> res;
        for (int d : people) {
            res.push_back(days_map[d]);
        }
        return res;
        */

        std::map<int, int> bloom_diffs;
        for (const auto& dates : flowers) {
            ++bloom_diffs[dates[0]];
            --bloom_diffs[dates[1] + 1];
        }

        std::map<int, int> bloom_counts;
        int cur_blooms = 0;
        for (const auto& [date, diff] : bloom_diffs) {
            cur_blooms += bloom_diffs[date];
            bloom_counts[date] = cur_blooms;
        }

        vector<int> res;
        for (int date : people) {
            auto iter = bloom_counts.lower_bound(date);
            if (iter == bloom_counts.end()) {
                res.push_back(0);
            } else if (iter->first == date) {
                res.push_back(iter->second);
            } else if (iter == bloom_counts.begin()) {
                res.push_back(0);
            } else {
                res.push_back((--iter)->second);
            }
        }
        return res;
    }
};