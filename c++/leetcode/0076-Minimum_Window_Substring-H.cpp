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
