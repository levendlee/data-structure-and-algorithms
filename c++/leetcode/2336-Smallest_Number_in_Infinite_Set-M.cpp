class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        intervals_[1] = INT_MAX;
        intervals_[-100] = -100;
    }
    
    int popSmallest() {
        auto iter = ++intervals_.begin();
        auto [start, end] = *iter;
        intervals_.erase(iter);
        if (start != end) {
            intervals_[start + 1] = end;
        }
        return start;
    }
    
    void addBack(int num) {
        auto iter = intervals_.lower_bound(num);
        auto [start, end] = *iter;
        auto [pstart, pend] = *(--iter);

        if (num <= pend || num >= start) {
            return;
        }

        if (num == pend + 1 && num == start - 1) {
            intervals_[pstart] = end;
            intervals_.erase(start);
        } else if (num == pend + 1) {
            intervals_[pstart] = pend + 1;
        } else if (num == start - 1) {
            intervals_[start - 1] = end;
            intervals_.erase(start);
        } else {
            intervals_[num] = num;
        }
    }

private:
    // Store intervals of integers. -1 stands for infinity.
    map<int, int> intervals_;
};
