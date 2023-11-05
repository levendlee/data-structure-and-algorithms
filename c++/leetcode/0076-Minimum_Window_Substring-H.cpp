// 76 Minimum Window Substring
// https://leetcode.com/problems/minimum-window-substring

// version: 1; create time: 2019-11-04 22:08:37;
class Solution {
public:
    string minWindow(string s, string t) {
        const int m = s.size();
        const int n = t.size();

        std::array<int, 256> limits;
        std::fill(limits.begin(), limits.end(), 0);

        std::array<int, 256> counter;
        std::fill(counter.begin(), counter.end(), 0);

        for (const auto& c : t) {
            ++limits[c];
        }

        int i = 0, j = 0, match = 0;
        std::string res;
        while (i < m) {
            if (match < n) {
                if (j == m) break;

                if ((counter[s[j]] < limits[s[j]]) && (limits[s[j]] != 0)) {
                    ++match;
                }
                ++counter[s[j]];

                ++j;
            } else {
                if (i == j) continue;

                int len = j - i;
                if (res.empty() || len < res.size()) {
                    res = s.substr(i, len);
                }

                if ((counter[s[i]] > 0) && (counter[s[i]] <= limits[s[i]]) && (limits[s[i]] != 0)) {
                    --match;
                }
                --counter[s[i]];
                ++i;
            }
        }

        return res;
    }
};


// version: 2; create time: 2020-02-22 19:17:16;
class Solution {
public:
    string minWindow(string s, string t) {
        const int n1 = s.size();
        const int n2 = t.size();

        int cnt[256] = {0};
        int tmp[256] = {0};
        for (auto c : t) ++cnt[c];

        string res;
        int covered = 0;
        int i = 0, j = 0;
        while (j < n1) {
            if (++tmp[s[j]] <= cnt[s[j]]) covered++;
            if (covered == n2) {
                while (tmp[s[i]] > cnt[s[i]]) tmp[s[i++]]--;
                if (res.empty() || res.size() > (j - i + 1)) {
                    res = s.substr(i, j - i + 1);
                }
            }
            ++j;
        }
        return res;
    }
};

// 2023/11/04

class Solution {
public:
    string minWindow(string s, string t) {
        string window;

        unordered_map<char, int> t_char_count;
        for (char c : t) {
            t_char_count[c] += 1;
        }

        const int m = s.size();
        const int n = t.size();

        int i = 0, j = 0, valid = 0;
        while (j < m) {
            while (j < m && valid < n) {
                auto iter = t_char_count.find(s[j]);
                if (iter != t_char_count.end()) {
                    valid += iter->second > 0;
                    iter->second -= 1;
                }
                ++j;
            }
            if (valid != n) continue;
            while (valid == n) {
                auto iter = t_char_count.find(s[i]);
                if (iter != t_char_count.end()) {
                    iter->second += 1;
                    valid -= iter->second > 0;
                }
                ++i;
            }
            if (window.empty() || window.size() > (j - i + 1)) {
                window = s.substr(i - 1, j - i + 1);
            }
        }

        return window;
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        string window;

        const int m = s.size(), n = t.size();
        int target[256] = {0};
        int current[256] = {0};
        int covered = 0;

        for (char c : t) {
            ++target[c];
        }

        int i = 0, j = 0;
        while (j < m) {
            if (++current[s[j]] <= target[s[j]]) {
                ++covered;
            }
            if (covered == n) {
                while (current[s[i]] > target[s[i]]) {
                    --current[s[i++]];
                };
                if (window.empty() || window.size() > (j - i + 1)) {
                    window = s.substr(i, j - i + 1);
                }
            }
            ++j;
        }

        return window;
    }
};
