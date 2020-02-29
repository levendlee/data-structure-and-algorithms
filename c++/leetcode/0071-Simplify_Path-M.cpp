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
