class DiningPhilosophers {
private:
    mutex mtx_;
    condition_variable cv_;
    vector<bool> forks_;

public:
    DiningPhilosophers() : forks_(5, false) {

    }

    void wantsToEat(int p,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int lf = p, rf = (p + 1) % 5;

		unique_lock<mutex> lk(mtx_);
        cv_.wait(lk, [&]{ return !forks_[lf] && !forks_[rf]; });
        pickLeftFork();
        pickRightFork();
        forks_[lf] = true;
        forks_[rf] = true;
        lk.unlock();

        eat();

        lk.lock();
        putLeftFork();
        putRightFork();
        forks_[lf] = false;
        forks_[rf] = false;
        lk.unlock();

        cv_.notify_one();
    }
};