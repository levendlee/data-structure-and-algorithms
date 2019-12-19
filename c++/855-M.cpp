struct Interval {
    int start;
    int end;
    Interval(int start, int end) : start(start), end(end) {

    }
    bool operator<(const Interval& rhs) const {
        return (end - start) < (rhs.end - rhs.start);
    }
};

class ExamRoom {
private:
    int n_;
    std::set<int> seats_;

public:
    ExamRoom(int N) : n_(N) {
    }

    int seat() {
        if (seats_.empty()) {
            seats_.insert(0);
            return 0;
        }

        int best_seat = 0;
        int best_dist = -1;

        const auto update = [&](int new_seat, int new_dist) {
            if (new_dist > best_dist) {
                best_seat = new_seat;
                best_dist = new_dist;
            }
        };

        int p = -1;
        int new_seat, new_dist;
        for (const auto& s : seats_) {
            if (p == -1) {
                new_seat = 0;
                new_dist = s;
            } else {
                new_seat = (p + s) / 2;
                new_dist = (s - p) / 2;
            }
            update(new_seat, new_dist);
            p = s;
        }
        if (p != n_ - 1) {
            new_seat = n_ - 1;
            new_dist = n_ - 1 - p;
        }
        update(new_seat, new_dist);

        seats_.insert(best_seat);
        return best_seat;
    }

    void leave(int p) {
        seats_.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */