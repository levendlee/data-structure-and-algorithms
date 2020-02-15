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