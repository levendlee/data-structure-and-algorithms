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