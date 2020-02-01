class MovingAverage {
private:
    long sum_;
    int size_;
    deque<int> dq_;

public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : sum_(0), size_(size) {

    }

    double next(int val) {
        sum_ += val;
        dq_.push_back(val);
        if (dq_.size() > size_) {
            sum_ -= dq_.front(); dq_.pop_front();
        }
        return 1.0 * sum_ / dq_.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */