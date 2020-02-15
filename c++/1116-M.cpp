class ZeroEvenOdd {
private:
    int n;
    int num;
    bool print_zero;

    mutex mtx_;
    condition_variable cv_;

    void run(function<bool()> cond, function<void()> printNumber) {
        while (num <= n) {
            unique_lock<mutex> lk(mtx_);
            cv_.wait(lk, [&]{ return num > n || cond(); });
            if (num > n) break;
            printNumber();
            lk.unlock();
            cv_.notify_all();
        }
    }

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        num = 1;
        print_zero = true;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        run([&]{ return print_zero; },
            [&]{ print_zero = false; printNumber(0); });
    }

    void even(function<void(int)> printNumber) {
        run([&]{ return !print_zero && !(num % 2);},
            [&]{ print_zero = true; printNumber(num++); });
    }

    void odd(function<void(int)> printNumber) {
        run([&]{ return !print_zero && (num % 2);},
            [&]{ print_zero = true; printNumber(num++); });
    }
};