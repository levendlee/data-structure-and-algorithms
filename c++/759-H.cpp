/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
class Solution {
private:
    map<int, int> bst_;

public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        bst_[INT_MIN] = INT_MAX;

        const auto cut_interval = [&](const Interval& free, const Interval& busy) {
            if (free.start < free.end) {
                int new_end = std::min(free.end, busy.start);
                if (free.start < new_end) {
                    bst_[free.start] = new_end;
                } else {
                    bst_.erase(free.start);
                }
                int new_start = std::max(free.start, busy.end);
                if (free.end > new_start) {
                    bst_[new_start] = free.end;
                }
            }
        };

        for (const auto& individual : schedule) {
            for (const auto& busy : individual) {
                Interval free0(INT_MAX, INT_MIN);
                Interval free1(INT_MAX, INT_MIN);
                const auto iter1 = bst_.upper_bound(busy.start);
                if (iter1 != bst_.begin()) {
                    auto tmp = iter1;
                    --tmp;
                    free0 = Interval(tmp->first, tmp->second);
                }
                const auto iter2 = bst_.lower_bound(busy.end);
                if (iter2 != iter1 && iter2 != bst_.begin()) {
                    auto tmp = iter2;
                    --tmp;
                    free1 = Interval(tmp->first, tmp->second);
                }
                bst_.erase(iter1, iter2);

                cut_interval(free0, busy);
                cut_interval(free1, busy);
            }
        }

        vector<Interval> res;
        for (const auto& p : bst_) {
            if (p.first != INT_MIN && p.second != INT_MAX)
                res.emplace_back(p.first, p.second);
        }
        return res;
    }
};