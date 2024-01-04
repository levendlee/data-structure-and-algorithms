// 621 Task Scheduler
// https://leetcode.com/problems/task-scheduler

// version: 1; create time: 2020-02-05 20:42:32;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int counter[26] = {0};
        for (const auto& c : tasks) {
            ++counter[c - 'A'];
        }
        std::sort(counter, counter + 26);
        /*
        int intervals = counter[25] - 1, idle_slots = intervals * n;
        for (int i = 24; i >= 0; --i) {
            idle_slots -= std::min(counter[i], intervals);
        }
        return idle_slots > 0 ? idle_slots + tasks.size() : tasks.size();
        */
        priority_queue<int> pq;
        for (int i = 0; i < 26; ++i) {
            pq.push(counter[i]);
        }
        queue<int> delay;
        for (int i = 0; i <= n; ++i) {
            delay.push(0);
        }
        int left = tasks.size();
        int time = 0;
        while (left) {
            auto prev = delay.front(); delay.pop();
            if (prev > 0) {
                pq.push(prev);
            }
            if (!pq.empty()) {
                auto cur = pq.top(); pq.pop();
                if (cur >= 1) {
                    delay.push(--cur);
                    --left;
                } else {
                    delay.push(0);
                }
            } else {
                delay.push(0);
            }
            time++;
        }
        return time;
    }
};

//

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int max_count = 0;
        int task_count[26] = {0};
        for (char t : tasks) {
            max_count = max(max_count, ++task_count[t - 'A']);
        }
        int cycles = (max_count - 1) * (n + 1);
        for (int cnt : task_count) {
            if (cnt == max_count) ++cycles;
        }
        return max(static_cast<int>(tasks.size()), cycles);
    }
};
