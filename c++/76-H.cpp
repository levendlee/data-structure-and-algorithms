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