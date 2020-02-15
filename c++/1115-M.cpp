class FooBar {
private:
    int n;
    bool print_foo;
    mutex mtx_;
    condition_variable foo_cv_;
    condition_variable bar_cv_;

public:
    FooBar(int n) {
        this->n = n;
        this->print_foo = true;
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lk(mtx_);
            foo_cv_.wait(lk, [&]{ return print_foo; });
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            print_foo = false;
            lk.unlock();
            bar_cv_.notify_one();
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lk(mtx_);
            bar_cv_.wait(lk, [&]{ return !print_foo; });
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            print_foo = true;
            lk.unlock();
            foo_cv_.notify_one();
        }
    }
};