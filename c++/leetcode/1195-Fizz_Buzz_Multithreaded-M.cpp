// 1195 Fizz Buzz Multithreaded
// https://leetcode.com/problems/fizz-buzz-multithreaded

// version: 2; create time: 2020-02-15 16:01:19;
class FizzBuzz {
private:
    int n;
    int num;
    mutex mtx_;

    condition_variable cv_;


public:
    FizzBuzz(int n) {
        this->n = n;
        this->num = 1;
    }

    void run(function<bool(int)> cond, function<void(int)> print) {
        while (num <= n) {
            unique_lock<mutex> lk(mtx_);
            cv_.wait(lk, [&]{ return (num > n) || cond(num); });
            if (num > n) return;
            print(num++);
            cv_.notify_all();
        }
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        run([](int num){ return !(num % 3) && (num % 5); }, [&](int i) { printFizz(); });
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        run([](int num){ return (num % 3) && !(num % 5); }, [&](int i) { printBuzz(); });
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        run([](int num){ return !(num % 3) && !(num % 5); }, [&](int i) { printFizzBuzz(); });
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        run([](int num){ return (num % 3) && (num % 5); }, [&](int i) { printNumber(i); });
    }
};


// version: 1; create time: 2020-02-15 15:51:23;
// Note: cv must break on num > n to avoid infinite wait
class FizzBuzz {
private:
    int n;
    int num;
    mutex mtx_;

    condition_variable cv_;

    void notify() {
        cv_.notify_all();
    }

public:
    FizzBuzz(int n) {
        this->n = n;
        this->num = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (num <= n) {
            unique_lock<mutex> lk(mtx_);
            cv_.wait(lk, [this]() { return (num > n) || !(num % 3) && (num % 5); });
            if (num > n) return;
            printFizz();
            ++num;
            notify();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (num <= n) {
            unique_lock<mutex> lk(mtx_);
            cv_.wait(lk, [this]() { return (num > n) || (num % 3) && !(num % 5); });
            if (num > n) return;
            printBuzz();
            ++num;
            notify();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (num <= n) {
            unique_lock<mutex> lk(mtx_);
            cv_.wait(lk, [this]() { return (num > n) || !(num % 3) && !(num % 5); });
            if (num > n) return;
            printFizzBuzz();
            ++num;
            notify();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (num <= n) {
            unique_lock<mutex> lk(mtx_);
            cv_.wait(lk, [this]() { return (num > n) || (num % 3) && (num % 5); });
            if (num > n) return;
            printNumber(num);
            ++num;
            notify();
        }
    }
};
