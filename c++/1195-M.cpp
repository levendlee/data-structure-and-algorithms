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