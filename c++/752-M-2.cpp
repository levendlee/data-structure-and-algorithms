class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadends_set;
        for (const auto& de : deadends) {
            deadends_set.insert(de);
        }
        if (deadends_set.count("0000")) return -1;

        unordered_set<string> visited;

        int steps = 0;
        queue<string> bfs;
        bfs.push("0000");

        auto try_push = [&](const string& lock) {
            if (deadends_set.count(lock) || visited.count(lock)) return;
            visited.insert(lock);
            bfs.push(lock);
        };

        while (!bfs.empty()) {
            for (int i = bfs.size() - 1; i >= 0; --i) {
                auto lock = bfs.front(); bfs.pop();
                for (int j = 0; j < 4; ++j) {
                    char c0 = lock[j] == '9' ? '0' : (lock[j] + 1);
                    auto forward = lock.substr(0, j) + c0 + lock.substr(j + 1);
                    if (forward == target) return steps + 1;
                    try_push(forward);

                    char c1 = lock[j] == '0' ? '9' : (lock[j] - 1);
                    auto backward = lock.substr(0, j) + c1 + lock.substr(j + 1);
                    if (backward == target) return steps + 1;
                    try_push(backward);
                }
            }
            ++steps;
        }
        return -1;
    }
};