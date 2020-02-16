class MyCalendarThree {
private:
    int max_events_;
    map<int, int> book_times_;

public:
    MyCalendarThree() : max_events_(0) {
        book_times_[INT_MIN] = 0;
    }

    int book(int start, int end) {
        auto iter0 = book_times_.upper_bound(start);
        auto iter1 = book_times_.upper_bound(end);
        auto iter3 = book_times_.insert({start, (--iter0)->second}).first;
        auto iter4 = book_times_.insert({end, (--iter1)->second}).first;
        for (auto iter = iter3; iter != iter4; ++iter) {
            max_events_ = max(max_events_, ++(iter->second));
        }
        return max_events_;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */