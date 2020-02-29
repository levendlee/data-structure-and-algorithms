// 295 Find Median from Data Stream
// https://leetcode.com/problems/find-median-from-data-stream

// version: 1; create time: 2019-12-30 11:34:15;
class MedianFinder {
private:
    std::priority_queue<int> left_;
    std::priority_queue<int> right_;

public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (!right_.empty() && num > -right_.top()) {
            right_.push(-num);
        } else {
            left_.push(num);
        }
        if (right_.size() > left_.size()) {
            left_.push(-right_.top());
            right_.pop();
        } else if (left_.size() > (right_.size() + 1)) {
            right_.push(-left_.top());
            left_.pop();
        }
    }

    double findMedian() {
        const int size = left_.size() + right_.size();
        int lval = left_.empty() ? 0 : left_.top();
        int rval = right_.empty() ? 0 : -right_.top();
        if (size % 2) {
            return lval;
        } else {
            return (lval + rval) / 2.0;
        }
    }
};
