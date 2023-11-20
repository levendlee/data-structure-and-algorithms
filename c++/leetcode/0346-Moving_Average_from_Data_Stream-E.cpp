// 346 Moving Average from Data Stream
// https://leetcode.com/problems/moving-average-from-data-stream

// version: 1; create time: 2020-02-01 14:47:26;
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

 //

 class MovingAverage {
public:
    MovingAverage(int size) {
        size_ = size;
        sum_ = 0;
    }

    double next(int val) {
        q_.push(val);
        sum_ += val;
        if (q_.size() > size_) {
            sum_ -= q_.front();
            q_.pop();
        }
        return sum_ * 1.0 / q_.size();
    }

private:
    int size_;
    int sum_;
    queue<int> q_;
};
