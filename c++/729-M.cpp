class MyCalendar {
private:
    map<int, int> events_;

public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        auto iter = events_.lower_bound(start);
        if (iter != events_.end() && iter->first < end) return false;
        if (iter != events_.begin() && (--iter)->second > start) return false;
        events_[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */