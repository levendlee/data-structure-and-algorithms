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