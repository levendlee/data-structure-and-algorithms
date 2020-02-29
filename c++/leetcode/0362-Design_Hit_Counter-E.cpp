// 362 Design Hit Counter
// https://leetcode.com/problems/design-hit-counter

// version: 1; create time: 2019-10-22 20:42:12;
class HitCounter {
private:
    std::queue<int> q_;

public:
    /** Initialize your data structure here. */
    HitCounter() {
    }

    void clear(int timestamp) {
        while (!q_.empty() && (timestamp - q_.front() >= 300)) {
            q_.pop();
        }
    }
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        clear(timestamp);
        q_.push(timestamp);
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        clear(timestamp);
        return q_.size();
    }
};

