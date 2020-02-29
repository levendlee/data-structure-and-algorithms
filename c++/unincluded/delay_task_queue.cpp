#include <time.h>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <unistd.h>
using namespace std;

typedef void(*func_t)();

struct Task {
    time_t timestamp;
    func_t p_func;
    Task(time_t timestamp, func_t p_func) : timestamp(timestamp), p_func(p_func) {
    }
    bool operator<(const Task& other) const {
        return timestamp > other.timestamp;
    }
};

class DelayTaskScheduler {
private:
    mutex mtx;
    condition_variable cv;
    bool ready;
    bool running;
    priority_queue<Task> pq;

public:
    DelayTaskScheduler() : ready(false), running(true) {
    }

    void maintainer() {
        while (running) {
            unique_lock<mutex> lk(mtx);
            //lk.lock();
            auto cur_timestamp = time(NULL);
            if (!pq.empty() && pq.top().timestamp < cur_timestamp) {
                ready = true;
            }
            lk.unlock();
            cv.notify_one();
            sleep(1);
        }
        cv.notify_all();
    }

    void consumer() {
        while (running) {
            func_t p_func = nullptr;
            unique_lock<mutex> lk(mtx);
            cv.wait(lk, [&]{ return ready || !running; });
            if (!running) return;
            auto cur_timestamp = time(NULL);
            if (!pq.empty() && pq.top().timestamp < cur_timestamp) {
                p_func = pq.top().p_func; pq.pop();
                ready = false;
            }
            lk.unlock();
            if (p_func != nullptr) {
                p_func();
            }
        }
    }

    void producer(func_t p_func, time_t delay) {
        unique_lock<mutex> lk(mtx);
        //lk.lock();
        auto cur_timestamp = time(NULL);
        pq.push({cur_timestamp + delay, p_func});
        lk.unlock();
    }

    bool hasTask() {
        unique_lock<mutex> lk(mtx);
        return !pq.empty();
    }

    void shutDown() {
        running = false;
    }
};

void print_a() {
    cout << "A\n";
}

void print_b() {
    cout << "B\n";
}

void print_c() {
    cout << "C\n";
}

int main() {
    DelayTaskScheduler scheduler;
    thread maintainer_thread(&DelayTaskScheduler::maintainer, &scheduler);
    thread consumer_thread(&DelayTaskScheduler::consumer, &scheduler);
    scheduler.producer(print_a, 5);
    scheduler.producer(print_b, 2);
    scheduler.producer(print_c, 1);
    while (scheduler.hasTask()) {
        sleep(1);
    }
    scheduler.shutDown();
    maintainer_thread.join();
    consumer_thread.join();
    return 0;
}

