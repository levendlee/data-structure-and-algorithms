// 752 Open the Lock
// https://leetcode.com/problems/open-the-lock

// version: 1; create time: 2019-12-23 10:58:47;
class Solution {
private:
    char forward(char c) {
        if (c < '9') {
            return c + 1;
        } else {
            return '0';
        }
    }

    char backward(char c) {
        if (c > '0') {
            return c - 1;
        } else {
            return '9';
        }
    }

public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") {
            return 0;
        }

        std::unordered_set<std::string> deadend;
        std::unordered_set<std::string> visited;
        int steps = 0;
        std::queue<std::string> bfs;

        // convert deadends from vector to hash set
        for (const auto& dd: deadends) {
            deadend.insert(dd);
        }
        if (deadend.count("0000")) {
            return -1;
        }

        // BFS search
        bfs.push("0000");
        while (!bfs.empty()) {
            const int n = bfs.size();
            for (int i = 0; i < n; ++i) {
                auto str = bfs.front();
                for (int j = 0; j < 2; ++j) {
                    for (int k = 0; k < 4; ++k) {
                        // Reuse string to avoid copy
                        char tmp = str[k];
                        str[k] = j ? forward(str[k]) : backward(str[k]);
                        if (str == target) {
                            return steps + 1;
                        }
                        if (!deadend.count(str) && !visited.count(str)) {
                            bfs.push(str);
                            visited.insert(str);
                        }
                        str[k] = tmp;
                    }
                }
                bfs.pop();
            }
            ++steps;
        }

        return -1;
    }
};


// version: 2; create time: 2020-02-19 21:45:36;
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
