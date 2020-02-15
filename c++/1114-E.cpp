class Foo {
private:
    int cnt_;
    mutex mtx_;
    condition_variable cv_;

public:
    Foo() : cnt_(0) {

    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        cnt_ = 1;
        cv_.notify_all();
    }

    void second(function<void()> printSecond) {
        {
            unique_lock<mutex> lk(mtx_);
            cv_.wait(lk, [this]() { return cnt_ == 1; });
            // printSecond() outputs "second". Do not change or remove this line.
            printSecond();
            cnt_ = 2;
        }
        cv_.notify_all();
    }

    void third(function<void()> printThird) {
        {
            unique_lock<mutex> lk(mtx_);
            cv_.wait(lk, [this]() { return cnt_ == 2; });
            // printThird() outputs "third". Do not change or remove this line.
            printThird();
            cnt_ = 3;
        }
    }
};