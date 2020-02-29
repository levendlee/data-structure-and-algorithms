// 1117 Building H2O
// https://leetcode.com/problems/building-h2o

// version: 1; create time: 2020-02-09 22:56:26;
class H2O {
private:
    std::mutex m;
    std::condition_variable o_cv;
    std::condition_variable h_cv;
    int o_cnt_;
    int h_cnt_;

public:
    H2O() : o_cnt_(1), h_cnt_(0) {

    }

    void hydrogen(function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lock(m);
        o_cv.wait(lock, [&]{ return o_cnt_ == 1; });
        if (h_cnt_ == 1) o_cnt_ = 0;
        h_cnt_++;
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        lock.unlock();
        if (h_cnt_ == 2) h_cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lock(m);
        h_cv.wait(lock, [&]{ return h_cnt_ == 2;});
        if (o_cnt_ == 0) h_cnt_ = 0;
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        o_cnt_++;
        lock.unlock();
        o_cv.notify_all();
    }
};
