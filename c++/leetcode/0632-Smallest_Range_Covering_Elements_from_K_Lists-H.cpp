// 632 Smallest Range Covering Elements from K Lists
// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists

// version: 1; create time: 2019-12-17 21:38:31;
class Solution {
private:
    struct Range {
        int start;
        int end;

        Range(int start, int end) : start(start), end(end) {}
        int dist() const { return end - start; }
        bool operator<(const Range& rhs) const {
            return (dist() < rhs.dist()) || (dist() == rhs.dist()) && (start < rhs.start);
        }
    };

    struct Elem {
        int val;
        int list;
        int index;

        Elem(int val, int list, int idx) : val(val), list(list), index(idx) {}
        bool operator<(const Elem& rhs) const {
            return val < rhs.val;
        }
    };

public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        const int n = nums.size();

        std::vector<int> indices(n, 0);
        std::priority_queue<Elem> min_heap, max_heap;
        for (int i = 0; i < n; ++i) {
            max_heap.emplace(nums[i][0], i, 0);
            min_heap.emplace(-nums[i][0], i, 0);
        }

        Range rng(-min_heap.top().val, max_heap.top().val);
        while (!min_heap.empty() && !max_heap.empty()) {
            const auto min_elem = min_heap.top(); min_heap.pop();
            const auto list = min_elem.list;
            const auto index = min_elem.index + 1;
            indices[list] = std::max(indices[list], index);

            if (index >= nums[list].size()) {
                return {rng.start, rng.end};
            }
            min_heap.emplace(-nums[list][index], list, index);

            while (!max_heap.empty() && max_heap.top().index < indices[max_heap.top().list]) {
                max_heap.pop();
            }
            max_heap.emplace(nums[list][index], list, index);

            Range new_rng(-min_heap.top().val, max_heap.top().val);
            if (new_rng < rng) {
                rng = new_rng;
            }
        }

        return {rng.start, rng.end};
    }
};
