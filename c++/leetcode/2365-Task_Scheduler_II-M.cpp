class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long cur = 0;

        unordered_map<int, int> days;
        const int n = tasks.size();
        for (int i = 0; i < n; ++i) {
            int t = tasks[i];
            auto iter = days.find(t);
            if (iter != days.end()) {
                int pre = iter->second;
                int needed = space - (cur - pre);
                if (needed > 0) {
                    cur += needed;
                }
            }
            ++cur;
            days[t] = cur;
        }

        return cur;
    }
};
