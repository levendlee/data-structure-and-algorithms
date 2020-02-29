// 731 My Calendar II
// https://leetcode.com/problems/my-calendar-ii

// version: 1; create time: 2019-12-26 17:28:48;
class MyCalendarTwo {
private:
    std::map<int, int> calendar_;

public:
    MyCalendarTwo() {

    }

    /*
    void clean(int loc) {
        if (calendar_.count(loc)) {
            if (calendar_[loc] == 0) {
                calendar_.erase(loc);
            }
        }
    }

    bool book(int start, int end) {
        calendar_[start] += 1;
        calendar_[end] -= 1;

        bool tripled = false;
        int concurrent = 0;
        for (const auto& event : calendar_) {
            concurrent += event.second;
            tripled = tripled || (concurrent >= 3);
        }

        if (tripled) {
            calendar_[start] -= 1;
            calendar_[end] += 1;
        }

        clean(start);
        clean(end);

        return !tripled;
    }
    */
    bool book(int start, int end) {
        auto s_iter0 = calendar_.lower_bound(start);
        int s_cnt = (s_iter0 != calendar_.begin()) ? (--s_iter0)->second : 0;
        auto e_iter0 = calendar_.lower_bound(end);
        int e_cnt = (e_iter0 != calendar_.begin()) ? (--e_iter0)->second : 0;

        auto s_iter = calendar_.insert(std::make_pair(start, s_cnt)).first;
        auto e_iter = calendar_.insert(std::make_pair(end, e_cnt)).first;
        for (auto iter = s_iter; iter != e_iter; ++iter) {
            if (iter->second >= 2) {
                return false;
            }
        }
        for (auto iter = s_iter; iter != e_iter; ++iter) {
            ++(iter->second);
        }
        return true;
    }

};
