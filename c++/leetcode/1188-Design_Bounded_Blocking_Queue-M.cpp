// 1188 Design Bounded Blocking Queue
// https://leetcode.com/problems/design-bounded-blocking-queue

// version: 1; create time: 2019-12-26 16:12:10;
class BoundedBlockingQueue {
private:
    int capacity_;
    std::queue<int> q_;
    std::mutex enqueue_mtx_;
    std::mutex dequeue_mtx_;
    std::condition_variable enqueue_cv_;
    std::condition_variable dequeue_cv_;

public:
    BoundedBlockingQueue(int capacity) : capacity_(capacity){

    }

    void enqueue(int element) {
        std::unique_lock<std::mutex> lock(enqueue_mtx_);
        // dequeue might happen, results in size() is smaller. but doesn't matter
        enqueue_cv_.wait(lock, [this]() { return size() < capacity_; });
        q_.push(element);
        dequeue_cv_.notify_one();
    }

    int dequeue() {
        std::unique_lock<std::mutex> lock(dequeue_mtx_);
        // enqueue might happen, results in size() is larger. but doesn't matter
        dequeue_cv_.wait(lock, [this]() { return size() > 0; });
        int element = q_.front(); q_.pop();
        enqueue_cv_.notify_one();
        return element;
    }

    int size() {
        return q_.size();
    }
};
