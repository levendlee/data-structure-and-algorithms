// 71 Simplify Path
// https://leetcode.com/problems/simplify-path

// version: 1; create time: 2020-02-05 22:20:16;
class Solution {
public:
    string simplifyPath(string path) {
        const int n = path.size();
        stack<string> dirs;
        int i = 0;
        while (i < n) {
            int j = path.find('/', i);
            j = j == string::npos ? n : j;
            if (j > i) {
                auto dir = path.substr(i, j - i);
                if (dir == ".") {
                    // nothing
                } else if (dir == "..") {
                    if (!dirs.empty()) dirs.pop();
                } else {
                    dirs.push(dir);
                }
            }
            i = j + 1;
        }
        string res;
        while (!dirs.empty()) {
            res = "/" + dirs.top() + res; dirs.pop();
        }
        return res.empty() ? "/" : res;
    }
};

// 2023/10/09
class Solution {
public:
    string simplifyPath(string path) {
        std::stack<string> stk;
        const int n = path.size();
        int i = 0;
        while (i < n) {
            while (i < n && path[i] == '/') {
                ++i;
            }

            int cnt = 0;
            int dot_cnt = 0;
            while (i < n && path[i] != '/') {
                ++cnt;
                dot_cnt += path[i] == '.';
                ++i;
            }
            if (cnt == 1 && dot_cnt == 1) {
                continue;
            } if (cnt == 2 && dot_cnt == 2) {
                if (!stk.empty()) {
                    stk.pop();
                }
            } else if (cnt > 0) {
                stk.push(path.substr(i - cnt, cnt));
            }
        }
        std::string res;
        while (!stk.empty()) {
            res.insert(0, stk.top());
            res.insert(0, "/");
            stk.pop();
        }
        if (res.empty()) {
            return "/";
        }
        return res;
    }
};
